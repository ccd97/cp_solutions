#include <bits/stdc++.h>

using namespace std;

inline bool ends_with(std::string const & value, std::string const & ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    unordered_map<string, unordered_set<string>> addd;
    for(int i=0; i<n; i++){
        string n, t1; cin>>n;
        int nc; cin>>nc;
        unordered_set<string> nos;
        for(int j=0; j<nc; j++){
            cin>>t1;
            nos.insert(t1);
        }
        if(addd.find(n) == addd.end()) addd.emplace(n, nos);
        else addd.at(n).insert(nos.begin(), nos.end());
    }
    for(auto& me: addd){
        unordered_set<string> suffixes;
        unordered_set<string> nonsuffixes;
        for(auto ne1: me.second){
            for(auto ne2: me.second){
                if(ne1 == ne2) continue;
                if(ends_with(ne2, ne1)){
                    suffixes.insert(ne1);
                }
            }
        }
        for(auto ne: me.second){
            if(suffixes.find(ne) == suffixes.end()){
                nonsuffixes.insert(ne);
            }
        }
        me.second = nonsuffixes;
    }

    cout<<addd.size()<<endl;
    for(auto me: addd){
        cout<<me.first<<" "<<me.second.size()<<" ";
        for(auto ne : me.second){
            cout<<ne<<" ";
        }
        cout<<endl;
    }
    return 0;
}
