#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    bool ply1 = (s[0] == '1');
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if((ply1 && s[i] == '1') || (!ply1 && s[i] == '0')) count++;
        if((ply1 && s[i] == '0') || (!ply1 && s[i] == '1')){ count = 1, ply1 = !ply1; }
        if(count > 6){ cout<<"YES"<<endl; return 0; }
    }
    cout<<"NO"<<endl;
    return 0;
}
