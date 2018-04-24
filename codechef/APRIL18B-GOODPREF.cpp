#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> calRes(string s, int n){
    vector<unsigned long long> anss;
    long as[s.length()+1], bs[s.length()+1];
    memset(as, 0, sizeof(as));
    memset(bs, 0, sizeof(bs));
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a'){
            as[i+1] = as[i] + 1;
            bs[i+1] = bs[i];
        }
        else{
            as[i+1] = as[i];
            bs[i+1] = bs[i] + 1;
        }
    }
    long long ans = 0;
    for(int i=1; i<=s.length(); i++){
        if(as[i] > bs[i]) ans++;
        if(i % n == 0) anss.push_back(ans);
    }
    return anss;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        string s, fs=""; unsigned long long n;
        cin>>s>>n;
        for(int i=0; i<1000; i++) fs += s;
        vector<unsigned long long> anss = calRes(fs, s.length());
        unsigned long long alen = anss.size();
        if(n <= anss.size()){
            cout<<anss[n-1]<<endl;
        }
        else{
            unsigned long long ans = anss[alen-1] + (anss[alen-1] - anss[alen-2]) * (n - alen);
            cout<<ans<<endl;
        }
     }
    return 0;
}
