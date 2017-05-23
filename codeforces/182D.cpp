#include <bits/stdc++.h>

using namespace std;

void computeLPSArray(string str, int n, int lps[]) {
    int len = 0, i=1;
    lps[0] = 0;
    while (i < n) {
       if (str[i] == str[len]) lps[i++] = ++len;
       else{
          if (len != 0) len = lps[len-1];
          else lps[i++] = 0;
       }
    }
}

int repeat_len(string str) {
    int n = str.size();
    int lps[n];
    computeLPSArray(str, n, lps);
    int len = lps[n-1];
    return (len > 0 && n%(n-len) == 0)?n-len:0;
}

int get_gcd(auto a, auto b) {
    if (a == 0) return b;
    return get_gcd(b%a, a);
}

int main(int argc, char const *argv[]) {
    string s1, s2; cin>>s1>>s2;
    int ns1 = s1.size(), ns2 = s2.size();
    int rls1 = repeat_len(s1);
    int rls2 = repeat_len(s2);
    if(rls1 == 0){
        for(int i=0; i<ns2; i+=ns1)
            for(int j=0; j<ns1; j++)
                if(s1[j] != s2[i+j])
                    { cout<<0<<endl; return 0; }
        cout<<1<<endl; return 0;
    }
    if(rls2 == 0){
        for(int i=0; i<ns1; i+=ns2)
            for(int j=0; j<ns2; j++)
                if(s2[j] != s1[i+j])
                    { cout<<0<<endl; return 0; }
        cout<<1<<endl; return 0;
    }
    if(rls1 != rls2){ cout<<0<<endl; return 0; }
    for(int i=0; i<rls1; i++){
        if(s1[i] != s2[i]) { cout<<0<<endl; return 0; }
    }
    int ans = 0;
    for(int i=rls1; i<=min(ns1, ns2); i+=rls1){
        if(ns1 % i == 0 && ns2 % i == 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
