#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
void maskToBitStr(vector<int> v, string & s){
    for(auto n : v){
        if(n == 0){
            s += "zzzzzzzz";
            continue;
        }
        string ss = "";
        while(n){
            ss.insert(ss.begin(), (n%2==1)?('1'):('z'));
            n/=2;
        }
        while(ss.length()<8){
            ss.insert(ss.begin(), 'z');
        }
        s += ss;
    }
}
 
int main() {
    
    string s = "";
    vector<vector<int>> ip;
    vector<vector<int>> mask;
    while(cin>>s){
        string sip = s.substr(0,s.find('~'));
        int i = 0;
        vector<int> t;
        while(sip.find('.') != string::npos){
            string ss = sip.substr(0, sip.find('.'));
            if(ss != ""){
                t.push_back(atoi(ss.c_str()));
            }
            sip.erase(0,  sip.find('.')+1);
        }
        if(sip!=""){
            t.push_back(atoi(sip.c_str()));       
        }
        ip.push_back(t);
         
        s.erase(0, s.find('~')+1);
        int j = 0;
        vector<int> u;
        while(s.find('.') != string::npos){
            string sm = s.substr(0, sip.find('.'));
            if(sm != ""){
                u.push_back(atoi(sm.c_str()));
            }
            s.erase(0, s.find('.')+1);
        }
        if(s != ""){
            u.push_back(atoi(s.c_str()));
        }
        mask.push_back(u);
    }
     
    int res[7] = {0};
    
    for(size_t i = 0; i < ip.size(); i++){
        bool rightIP = true;
        bool rightMask = true;
        string bs = "";
        maskToBitStr(mask[i], bs);      
         
        if(ip[i][0]==0 || ip[i][0]==127){
            continue;
        }

        if(ip[i].size()<4){
            res[5]++;
            rightIP = false;
        }
        
        size_t stz = 0;
        size_t st1 = 0;
        if(mask[i].size()<4 || bs.find('z')==string::npos || bs.find('1')==string::npos){
            res[5]++;
            rightMask = false;
        }else{
            stz = bs.find('z');
            st1 = bs.rfind('1');  
            if(stz<st1){
                res[5]++;
                rightMask = false;
            }
        } 
        
        if(rightIP && rightMask)
        {              
            if((ip[i][0]>=1&&ip[i][0]<=126)&&(ip[i][1]>=0&&ip[i][1]<=255)&&(ip[i][2]>=0&&ip[i][2]<=255)&&(ip[i][3]>=0&&ip[i][3]<=255)){
                res[0]++;
                if(ip[i][0]==10){
                    res[6]++;
                }
            }else if((ip[i][0]>=128&&ip[i][0]<=191)&&(ip[i][1]>=0&&ip[i][1]<=255)&&(ip[i][2]>=0&&ip[i][2]<=255)&&(ip[i][3]>=0&&ip[i][3]<=255)){
                res[1]++;             
                if(ip[i][0]==172&&(ip[i][1]>=16&&ip[i][1]<=31)){
                    res[6]++;
                }
            }else if((ip[i][0]>=192&&ip[i][0]<=223)&&(ip[i][1]>=0&&ip[i][1]<=255)&&(ip[i][2]>=0&&ip[i][2]<=255)&&(ip[i][3]>=0&&ip[i][3]<=255)){
                res[2]++;            
                if(ip[i][0]==192&&ip[i][1]==168&&(ip[i][2]>=0&&ip[i][2]<=255)){
                    res[6]++;
                }
            }else if((ip[i][0]>=224&&ip[i][0]<=239)&&(ip[i][1]>=0&&ip[i][1]<=255)&&(ip[i][2]>=0&&ip[i][2]<=255)&&(ip[i][3]>=0&&ip[i][3]<=255)){
                res[3]++;
            }else if((ip[i][0]>=240&&ip[i][0]<=255)&&(ip[i][1]>=0&&ip[i][1]<=255)&&(ip[i][2]>=0&&ip[i][2]<=255)&&(ip[i][3]>=0&&ip[i][3]<=255)){
                res[4]++;
            }  
        }
        
    }
     
    for(auto n : res){
        cout<<n<<" ";
    }
    
}