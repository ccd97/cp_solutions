#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    bool flag = false;
    bool flag1 = true;
    for(int i=0; i<s.size(); i++){
        if(flag1 && s[i] != '0'){
            flag1 = false;
        }
        else if(s[i] == '0' && !flag && !flag1){
            flag = true;
            continue;
        }
        if(i !=s.size()-1 || flag) cout<<s[i];
    }
    cout<<endl;
    return 0;
}
