#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 1
bool veri(string a, string b) { // verify: same-size POE:
    // cout << a << " " << b << endl;
    char va[26] = {0}, vb[26] = {0};
    if (a == b) { // POE:
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        ++va[a[i] - 'a'];
        ++vb[b[i] - 'a'];
    }

    for (int i = 0; i < 26; i++) {
        if (va[i] != vb[i]) {
            return false;
        }
    }

    // cout << "--- " << a << " " << b << endl;
    return true;
}
#endif
#if 0
bool veri(string s1, string s2){  //查看是否是兄弟单词 // POE:
    if (s1.length() == s2.length()) { //兄弟单词一定要长度相等
        if(s1 == s2) //不能是同一个
            return false;
        sort(s1.begin(), s1.end());  //对两个字符串按字符字典序排序
        sort(s2.begin(), s2.end());
        if(s1 == s2) //排序后一样才是改变位置能办到的
            return true;
    }
    return false;
}
#endif
int main() {
    string t;
    int n, k;
    cin >> n;

    vector<string> rst; // dict-set-raw // POE:
    for (int i = 0; i < n; i++) {
        cin >> t;
        rst.push_back(t);
        // cout << t << endl;
    }
    cin >> t; // raw-string
    // cout << t;
    cin >> k; // k-index
    // cout << k;

    vector<string> dst; // dict-set
    for (auto it = rst.begin(); it != rst.end(); it++) {
        string tmp = *it;
        // cout << tmp << " " << tmp.size() << " " << t.size();
        if (tmp.size() != t.size()) { // char-num-not-same
            // rst.erase(it); // POE:
            // ++it;
            // cout << tmp << " ";
            continue;
        } else { // char-num-same
            if (!veri(t, tmp)) { // POE:
                continue;
            }
            // set<char> cst(t.begin(), t.end()); // char-set
            // set<char> cst2(tmp.begin(), tmp.end());
            // if (cst != cst2) {
            //     continue;
            // }
            // for (int i = 0; i < tmp.size(); i++) {
            //     if (!cst.count(tmp[i])) {
            //         continue;
            //     }
            // }
        }
        dst.push_back(*it);
        // cout << *it << " ";
    }
    sort(dst.begin(), dst.end()); // POE: no-need
 
    cout << dst.size() << endl;

    for (auto it = dst.begin(); it != dst.end(); ++it) {
    // for (auto it : dst) {
        // cout << k << endl;
        // cout << *it << " ";
        string tmp = *it; // POE:
        // if (dst.count(t)) {
        //     continue;
        // }
        --k;
        
        if (k == 0) {
            cout << *it;
        }
    }

    return 0;
}
// 3 abc bca cab abc 1
// 2
// bca
// 473 bb daccb caddd bddc c baa adb ad abbcb cdaa abab a abcc ddcbd cadcc cdacd aaa a b acccd bbb dacc cc acbdd bcbb ba bacaa adda acd aaad d ab acac bc dabab abcd aacba aba daa bb ad cddab a bbaa aacad cdac acbcc cada bacd adcad cdadc bcbcc aa b acd cbaac ddcd ccb dac a dac adbcb bcda dda a ab ca dd d abd a dbb ccabd bdddd abd adc aaa baccb ccdcd a da c cadc dcdbd d aa bb a cac c ad adb ca cdcc cadd dddca d cba cb caab caa dd cd bca abc cdaa cdb bad dad bda d ddbc dab baaa adaac b a dbccd bd b bdad cdacd baa ac ddcad d bb acc aa cd cbdbb bbbcb a cc aacc c aadc dbcd a bca dd abbb ccdcd ccd ab d a a dadcd dbd bcaa c cda b ddab caaaa cdcdb b acbc ccaa dabca dcd b ba dbcc da bdbcc ab abaca bb cddc caca da dadba accdd bdac dbcd bcbbd ab bd ccb ddaa aa b b d bddd cabac aaba ab ccdb db abbd ada bdadb c abba dd cdb bca cccda badba abaa ac aabad db ccbad bddd ada dba acba b bc dd bbbbd cc cbdd cd abcaa bb ddaca acadb bbbb bddcc bdada aaa bcbda c aaa aadd cdddc adb cdbab c cbca bb aacab acdb bbdab b acbda cbdcd bda bacdc db d adcbd bccc c aaa cdd bdcd bac a aaab ddbb cd ccdbb addcc cdc c ca baadc addba dbdbd dba bbdda bcb c cdad aacac dcada cb aaad a cccab caca aad bbb dd b babbb cba bdaca db bacd bc bcbda cdda bcccd bdcda bdbcd adb cbcb a c bacba abbb adab adab b b d bca badbc baa cdb b abc aabb b d c cdab cacda d cdcda adcdc bcc bbccd b adb caba cbaaa aadb dcc add bcac bacbd bb a b c cabaa c caad c aa bcc ccab ddc dadca cdcba aaba dabbd dcb a bddb bb a c c cbc ccd dd a cabbb b caadb cb dca cbb ddaa bcadc dab a bbda cd bc ccad bbd ab c acddd cdd dbbbb daaab abbb cabc add ca caa bbbb dcab daaaa baca dcd ccacb ba bddaa acac dbcc bcc cbbcc b abba daa dbab bcca ba aa d dcdc d dcaa cbcda bd b ccbcb baa dcacd d c cbda baba d abb c cbdc da dbbb cd aabc dadc b a ddb c ddd ccdc ccd cba dbaac dcccd ddbac dbbdd bad bcdd cb dac dccd d a acdd d c cb b bcbb c a aca bcba d d bbdbc d c dabad ccca dc adb ddb dcdd dba ad ddaba c ac ddac bbbd cd a dacbb 1
// 6
// adbcb
// 106
// aabad
// 64 位输出请用 printf("%lld")