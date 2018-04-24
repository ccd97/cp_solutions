#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long nCr(int n, int r) {
    long C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]);
    }
    return C[r];
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size() == 1) { cout<<0<<endl; continue; }
        if(s.size() == 2 && s[0] == s[1]) { cout<<1<<endl; continue; }
        int i=0, j=1;
        long res = 0;
        bool match = false;
        while(true){
            if(i > s.size() || j > s.size()) break;
            if(s[i] == s[j]){
                match = true;
                j++;
            }
            else{
                if(match){
                    match = false;
                    res += nCr(j-i, 2);
                    if(j < s.size() && s[i-1] == s[j]) res++;
                    i = j;
                    j++;
                }
                else{
                    i++;
                    j++;
                }

            }
        }
        for(int i=0; i<s.size()-2; i++){
            if(s[i]==s[i+2] && s[i] != s[i+1]) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
