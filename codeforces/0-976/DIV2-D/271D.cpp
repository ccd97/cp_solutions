#include <bits/stdc++.h>

using namespace std;

unsigned long long phash[2002];
unsigned long long power[2002];

struct string_hash{
    unsigned long long prime = 1000000009;

    string_hash(string s){
        long n = s.size();
        power[0] = 1, phash[0] = 0;
        for(int i=0; i<=n; i++){
            power[i+1] = power[i] * prime;
            phash[i+1] = phash[i] * prime + s[i];
        }
    }

    auto hash(long s, long e){
        return phash[e+1] - phash[s] * power[e-s+1];
    }

};

unordered_map<unsigned long long, list<pair<int, int>>> goodset;

int main(int argc, char const *argv[]) {
    string s, gb; int k;
    cin>>s>>gb>>k;

    int bc[s.size()+1]; bc[0] = 0;

    for(size_t i=0; i<s.size(); i++){
        bc[i+1] = bc[i] + (gb[s[i]-'a']=='0'?1:0);
    }

    string_hash sh(s);
    long collosions = 0;

    for(size_t i=0; i<s.size(); i++){
        for(size_t j=i; j<s.size(); j++){
            if(bc[j+1] - bc[i] <= k){
                auto hsh = sh.hash(i, j);
                auto it = goodset.find(hsh);
                pair<int, int> pr = {i,j};
                if(it == goodset.end()){
                    list<pair<int,int>> lst = {pr};
                    goodset.emplace(hsh, lst);
                }
                else{
                    bool found = false;
                    for(auto gpr : it->second){
                        if(s.substr(i, j-i+1) == s.substr(gpr.first, gpr.second-gpr.first+1)){
                            found = true; break;
                        }
                    }
                    if(!found){
                        it->second.push_back(pr);
                        collosions++;
                    }
                }
            }
        }
    }
    cout<<goodset.size()+collosions<<endl;
    return 0;
}
