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
int main() {
    string t;
    int na = 0; 
    int nb = 0; 
    int nc = 0; 
    int nd = 0; 
    int ne = 0; 
    int ni = 0; // number of invalid;
    int np = 0; // number of private;
    while (getline(cin, t)) {
        int len = t.length();
        int tilde = t.find('~'); // seperate: ~
        string s_ip = t.substr(0, tilde);
        string s_mk = t.substr(tilde + 1, len - tilde - 1);

        // Step-1: Ignoring 0.*.*.* and 127.*.*.*;
        int ip_p1 = s_ip.find('.');
        string ip1 = s_ip.substr(0, ip_p1);
        if (ip1 == "0" || ip1 == "127") {
            continue;
        }
        
        // Step-2: Verifying mask;
        int mk_p1 = s_mk.find('.');
        string mk1 = s_mk.substr(0 ,mk_p1); 
        if (mk1 == "" || stoi(mk1) > 255) {
            ni++;
            continue;
        }
        bitset<8> bmk1(stoi(mk1)); // POK: int to bitset;

        int mk_p2 = s_mk.find('.' , mk_p1 + 1);
        string mk2 = s_mk.substr(mk_p1 + 1 , mk_p2 - mk_p1 - 1 ); 
        if (mk2 == "" || stoi(mk2) > 255) {
            ni++;
            continue;
        }
        bitset<8> bmk2(stoi(mk2));
        
        int mk_p3 = s_mk.find('.', mk_p2 + 1);
        string mk3 = s_mk.substr(mk_p2 + 1, mk_p3 - mk_p2 -1 );
        if (mk3 == "" || stoi(mk3) > 255) {
            ni++;
            continue;
        }
        bitset<8> bmk3(stoi(mk3));

        string mk4 = s_mk.substr(mk_p3 + 1, s_mk.length() - mk_p3 - 1);
        if (mk4 == "" || stoi(mk4) > 255) {
            ni++;
            continue;
        }
        bitset<8> bmk4(stoi(mk4));
        
        // Error-Mask: All zero or all one;
        if (bmk1.count() + bmk2.count() + bmk3.count() + bmk4.count() == 32 ||
                bmk1.count() + bmk2.count() + bmk3.count() + bmk4.count() == 0) {
            ni++;
            continue;
        }
        int vMask[32] = {0};
        for (int i = 0; i < 32; i++) {
            if (i >= 0 && i <= 7) {
                vMask[i] = bmk1[7 - i];
            } else if (i >= 8 && i <= 15){
                vMask[i] = bmk2[7 - i + 8];
            } else if (i >= 16 && i <= 23){
                vMask[i] = bmk3[7 - i + 16];
            } else if (i >= 24 && i < 31) {
                vMask[i] = bmk4[7 - i + 24];
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
            ni++;
            continue;
        }

        // Step-3: Verify IP correctness;
        if (ip1 == "" || stoi(ip1) > 255){
            ni++;
            continue;
        }
        
        int ipPoint2 = s_ip.find('.' , ip_p1 +1 );
        string ip2 = s_ip.substr(ip_p1 + 1, ipPoint2 - ip_p1 - 1);
        if(ip2 == "" || stoi(ip2) > 255){
            ni++;
            continue;
        }
        int ipPoint3 = s_ip.find('.' , ipPoint2 +1 );
        string ip3 = s_ip.substr(ipPoint2 + 1, ipPoint3 - ipPoint2 - 1);
        if(ip3 == "" || stoi(ip3) > 255){
            ni++;
            continue;
        }
        
        string ip4 = s_ip.substr(ipPoint3 + 1 , s_ip.length() - ipPoint3 - 1);
        if(ip4 == "" || stoi(ip4) > 255){
            ni++;
            continue;
        }

        // Step-4: All clear, classify IP to A-B-C-D-E;
        int judge1 = stoi(ip1);
        int judge2 = stoi(ip2);
        if (judge1 >= 1 && judge1 <= 126){ // A 类
            na++;
            if(judge1 == 10){
                np++;
            }
        }
        else if (judge1 >= 128 && judge1 <= 191){ // B 类
            nb++;
            if(judge1 == 172 &&  judge2 >= 16 && judge2 <= 31){
                np++;
            }
        }
        else if (judge1 >= 192 && judge1 <= 223){// C 类
            nc++;
            if(judge2 == 168){
                np++;
            }
        }
        else if (judge1 >= 224 && judge1 <= 239){// D 类
            nd++;
        }
        else if (judge1 >= 240 && judge1 <= 255){// E 类
            ne++;
        }
    }
    
    cout<<na<<" "<<nb<<" "<<nc<<" "<<nd<<" "<<ne<<" "<<ni<<" "<<np<<" "<<endl;
}

