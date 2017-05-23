#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    string ans = "";
    int i=0;
    bool first = true;
    while(i < s.size()){
        if(i + 2 < s.size() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            if(!(i + 5 < s.size() && s[i+3] == 'W' && s[i+4] == 'U' && s[i+5] == 'B')){
                if(!first) {
                    ans += " ";
                }
            }
            i += 3;
            continue;
        }
        ans += s[i++];
        first = false;
    }
    cout<<ans<<endl;
    return 0;
}
