#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

//思路：（首先排除0.*.*.* 和127.*.*.* 的IP地址 ，因为这种IP地址不属于任何一类需要计数的类型）
//1.判断子网掩码是否正确：错误属于IP或掩码错误情况，相应计数加1，继续下一条字符串判断,重新开始1；正确进入2
//2.此时掩码正确，判断IP地址是否正确：错误属于IP或掩码错误情况，相应计数加1，继续下一条字符串判断,重新开始1；正确进入3
//3.此时IP正确，判段属于A/B/C/D/E哪类地址，同时判断是否属于私有地址，相应计数加1，继续下一条字符串判断，重新开始1
int main(){
    string mstr;
    //计数变量
    int Aaddress = 0; 
    int Baddress = 0; 
    int Caddress = 0; 
    int Daddress = 0; 
    int Eaddress = 0; 
    int ErrorIpOrMask = 0; 
    int PrivateIP = 0;
    while (getline(cin, mstr)) {
        //获取两个字符串 ， IP地址和子网掩码
        int len = mstr.length();//单个字符串的长度
        int Middle = mstr.find('~'); //查找 ~ 的位置 
        string strIp = mstr.substr(0,Middle);//存放单个字符串Ip地址部分//stringA.substr(int startIndex, int needLength)
        string strMask = mstr.substr(Middle+1,len - Middle- 1 );//存放单个字符串子网掩码部分

        // Step-1: Exclude 0.*.*.* and 127.*.*.*;
        int ipPoint1 = strIp.find('.');
        string ip1 = strIp.substr(0, ipPoint1);
        if (ip1 == "0" || ip1 == "127"){
            continue;
        }
        
        //判断子网掩码是否正确
        int maskPoint1 = strMask.find( '.' );//查找子网掩码中第1个点
        string mask1 = strMask.substr(0 ,maskPoint1); 
        if( mask1 == "" || stoi(mask1) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask1(stoi(mask1)); //将字符串形式的数字转为整型后，获取其8位二进制值

        int maskPoint2 = strMask.find( '.' , maskPoint1 + 1);//从maskPoint1 + 1位置开始，查找子网掩码中第2个点
        string mask2 = strMask.substr(maskPoint1 + 1 , maskPoint2 - maskPoint1 - 1 ); 
        if( mask2 == "" || stoi(mask2) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask2(stoi(mask2));
        
        int maskPoint3 = strMask.find( '.' ,maskPoint2 + 1);//查找子网掩码中第一个点
        string mask3 = strMask.substr(maskPoint2 + 1, maskPoint3 - maskPoint2 -1 );
        if( mask3 == "" || stoi(mask3) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask3(stoi(mask3));

        string mask4 = strMask.substr(maskPoint3+1 , strMask.length() - maskPoint3 -1 );
        if( mask4 == "" || stoi(mask4) > 255 ){ //不能为空位
            ErrorIpOrMask++;
            continue;
        }
        bitset<8> bMask4(stoi(mask4));
        
        // Error-Mask: All zero or all one;
        if(bMask1.count() + bMask2.count() + bMask3.count() + bMask4.count() == 32 ||
          bMask1.count()+ bMask2.count() + bMask3.count() + bMask4.count() == 0){
            ErrorIpOrMask++;
            continue;
        }
        int vMask[32] = {0};//将二进制的子网掩码放入整型数组vMask，用于判断子网掩码中的连续1
        for(int i = 0 ; i< 32 ;i++){
            if(i>=0 && i<= 7){
                vMask[i] = bMask1[7 - i];
            }
            else if(i>=8 && i<= 15){
                vMask[i] = bMask2[ 7 - i + 8];
            }
            else if(i>=16 && i <= 23){
                vMask[i] = bMask3[7 - i+ 16];
            }
            else if(i>=24 && i< 31){
                vMask[i] = bMask4[7- i + 24];
            }
        }
        
        bool ErrorContinue = false; //判断是否存在连续的1 ，不连续1非法 i,j 双指针判断
        for(int i = 0 , j = 1 ; j < 32 ;  ){
            if(vMask[i] == 0 && vMask[j] == 1){ //对一串子网掩码而言，出现 ****01***即是非法的掩码
                ErrorContinue = true;
                break;
            }
            i++;
            j++;
        }
        if(ErrorContinue){
            ErrorIpOrMask++;
            continue;
        }

        // Step-3: Verify IP correctness;
        if (ip1 == "" || stoi(ip1) > 255){
            ErrorIpOrMask++;
            continue;
        }
        
        int ipPoint2 = strIp.find('.' , ipPoint1 +1 );
        string ip2 = strIp.substr(ipPoint1 + 1, ipPoint2 - ipPoint1 - 1);
        if(ip2 == "" || stoi(ip2) > 255){
            ErrorIpOrMask++;
            continue;
        }
        int ipPoint3 = strIp.find('.' , ipPoint2 +1 );
        string ip3 = strIp.substr(ipPoint2 + 1, ipPoint3 - ipPoint2 - 1);
        if(ip3 == "" || stoi(ip3) > 255){
            ErrorIpOrMask++;
            continue;
        }
        
        string ip4 = strIp.substr(ipPoint3 + 1 , strIp.length() - ipPoint3 - 1);
        if(ip4 == "" || stoi(ip4) > 255){
            ErrorIpOrMask++;
            continue;
        }

        // Step-4: All clear, classify IP to A-B-C-D-E;
        int judge1 = stoi(ip1);
        int judge2 = stoi(ip2);
        if (judge1 >= 1 && judge1 <= 126){ // A 类
            Aaddress++;
            if(judge1 == 10){
                PrivateIP++;
            }
        }
        else if (judge1 >= 128 && judge1 <= 191){ // B 类
            Baddress++;
            if(judge1 == 172 &&  judge2 >= 16 && judge2 <= 31){
                PrivateIP++;
            }
        }
        else if (judge1 >= 192 && judge1 <= 223){// C 类
            Caddress++;
            if(judge2 == 168){
                PrivateIP++;
            }
        }
        else if (judge1 >= 224 && judge1 <= 239){// D 类
            Daddress++;
        }
        else if (judge1 >= 240 && judge1 <= 255){// E 类
            Eaddress++;
        }
    }
    
    cout<<Aaddress<<" "<<Baddress<<" "<<Caddress<<" "<<Daddress<<" "<<Eaddress<<" "<<ErrorIpOrMask<<" "<<PrivateIP<<" "<<endl;
}

