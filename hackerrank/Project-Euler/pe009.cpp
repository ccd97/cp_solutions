#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_map<int, long long> mp;
    for(long long i=1; i<3000; i++){
        for(long long j=i; j<3000; j++){
            long long root = round(sqrt(i*i + j*j));
            if(i*i + j*j == root * root){
                auto peri = i + j + root;
                auto it = mp.find(peri);
                if(it == mp.end()) mp.emplace(peri, i*j*root);
                else it->second = max(it->second, i*j*root);
            }
        }
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        auto it = mp.find(n);
        if(it == mp.end()) cout<<-1<<endl;
        else cout<<it->second<<endl;
    }
    return 0;
}
