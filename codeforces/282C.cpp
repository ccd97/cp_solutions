#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s1, s2; cin>>s1>>s2;
    if(s1.size() != s2.size())
        { cout<<"NO"<<endl; return 0; }
    bool s1c1 = false, s2c2 = false;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] == '1') s1c1 = true;
        if(s2[i] == '1') s2c2 = true;
    }
    if(s1c1 != s2c2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
