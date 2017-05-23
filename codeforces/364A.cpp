#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long a, sm; cin>>a;
    string s; cin>>s;
    long long cs[40004]; cs[0] = 0;
    for(int i=0; i<s.size(); i++) cs[i+1] = cs[i] + (s[i] - '0');
    unordered_map<long long, long long> mp;
    long long count = 0;
    for(int i=0; i<s.size()+1; i++){
        for(int j=i+1; j<s.size()+1; j++){
            sm = cs[j]-cs[i];
            count++;
            auto it = mp.find(sm);
            if(it == mp.end()) mp.emplace(sm, 1);
            else it->second++;
        }
    }
    long long ans = 0;
    for(auto p: mp){
        if(p.first==0 && a == 0) ans += p.second*count;
        else if(p.first == 0) continue;
        else if(a%p.first==0){
            auto it = mp.find(a/p.first);
            if(it != mp.end()){
                ans += p.second*it->second;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
