#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, mans=0; cin>>n;
    string s; cin>>s;
    if(s.size() > 1)
    for(char i='a'; i<='z'; i++){
        for(char j='a'; j<='z'; j++){
            int ans = 0;
            char prev = 0;
            for(int k=0; k<s.size(); k++){
                if(s[k] == i || s[k] == j){
                    if(prev == s[k]){
                        ans = 0;
                        break;
                    }
                    else{
                        prev = s[k];
                        ans++;
                    }
                }
            }
            if(ans > mans) mans = ans;
        }
    }
    cout<<mans<<endl;
    return 0;
}
