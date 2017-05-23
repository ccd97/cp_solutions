#include <bits/stdc++.h>

using namespace std;

vector<int> gph[100005];
int color[100005];

int main(int argc, char const *argv[]) {
    int n, m, t1, t2; cin>>n>>m;
    unordered_map<int, unordered_set<int>> mp;
    for(int i=0; i<n; i++){
        cin>>color[i];
        unordered_set<int> tmp;
        mp.emplace(color[i], tmp);
    }
    for(int i=0; i<m; i++){
        cin>>t1>>t2; t1--, t2--;
        gph[t1].push_back(t2);
        gph[t2].push_back(t1);
    }
    for(int i=0; i<n; i++){
        unordered_set<int> st;
        for(int j=0; j<gph[i].size(); j++){
            if(color[gph[i][j]] != color[i]){
                mp[color[i]].insert(color[gph[i][j]]);
            }
        }
    }
    int mx=-1, mcolor=-1;
    for(auto mpe: mp){
        int mpesz = mpe.second.size();
        if(mpesz > mx || (mpesz == mx && mpe.first < mcolor)){
            mx = mpesz;
            mcolor = mpe.first;
        }
    }
    cout<<mcolor<<endl;
    return 0;
}
