#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t, tmp; cin>>t;
    while(t--){
        unordered_map<int, int> pmap;
        for(int i=0; i<4; i++){
            cin>>tmp; if(tmp == 0) continue;
            auto it = pmap.find(tmp);
            if(it != pmap.end()) it->second++;
            else pmap.emplace(tmp, 1);
        }
        if(pmap.size() == 2 && pmap.begin()->second == 2 && (++pmap.begin())->second == 2){
            cout<<"YES"<<endl;
        }
        else if(pmap.size() == 1 && pmap.begin()->second == 4){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
