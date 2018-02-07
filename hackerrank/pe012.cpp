#include <bits/stdc++.h>

#define LIMIT 500005

using namespace std;

int main(int argc, char const *argv[]) {
    int fact[LIMIT];
    memset(fact, 0, sizeof(fact));
    for(int i=1; i<LIMIT; i++){
        for(int j=1; j<LIMIT; j+=i){
            fact[j-1]++;
        }
    }
    map<int, long long> mp;
    for(int i=1; i<LIMIT; i++){
        long long a = (i%2 == 0)?i/2:i;
        long long b = ((i+1)%2 == 0)?(i+1)/2:i+1;
        long long f = fact[a] * fact[b];
        auto it = mp.find(f);
        if(it == mp.end()) mp.emplace(f, a*b);
        else it->second = min(it->second, a*b);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long ans = LLONG_MAX;
        for(auto p : mp){
            if(p.first > n) ans = min(ans, p.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}
