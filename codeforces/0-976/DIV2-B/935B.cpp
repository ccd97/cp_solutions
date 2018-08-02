#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, ans = 0; cin>>n;
    string s; cin>>s;
    int xi = 0, yi = 0;
    int reg = 0;
    for(char c : s){
        if(c == 'U') yi++;
        else xi++;
        if(reg == 0 && xi - yi > 0) reg = 1;
        else if(reg == 0 && xi - yi < 0) reg = -1;
        else if(reg == 1 && xi - yi < 0){
            reg = -1; ans++;
        }
        else if(reg == -1 && xi - yi > 0){
            reg = 1; ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
