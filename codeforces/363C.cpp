#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    char chs[s.length()];
    int ctns[s.length()];
    memset(ctns, 0, sizeof(ctns));
    int idx = 0; chs[idx] = s[0]; ctns[idx]++;
    for(int i=1; i<s.length(); i++){
        if(s[i] == chs[idx]) ctns[idx]++;
        else{
            idx++;
            chs[idx] = s[i];
            ctns[idx]++;
        }
    }
    string result = "", sp="";
    for(int i=0; i<s.length(); i++){
        if(ctns[i] < 2){
            for(int j=0; j<sp.length(); j++){
                result += sp[j];
                if(j%2 == 0){
                    result += sp[j];
                }
            }
            if(ctns[i] == 0) break;
            result += chs[i];
            sp = "";
        }
        else{
            sp += chs[i];
        }
    }
    cout<<result<<endl;
    return 0;
}
