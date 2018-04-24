#include <bits/stdc++.h>

using namespace std;

bool gph[105][105];
bool visited[105];

void dfs(int v, int mx){
    visited[v] = true;
    for(int i=0; i<mx; i++){
        if(!visited[i] && gph[v][i] == true){
            dfs(i, mx);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, m, k, t1, t2; cin>>n>>m;
    int ans = 0;
    for(int i=0; i<m+1; i++){
        visited[i] = false;
        for(int j=0; j<m+1; j++){
            gph[i][j] = false;
        }
    }
    vector<int> singles;
    unordered_set<int> si;
    int cc = 0;
    for(int i=0; i<n; i++){
        cin>>k;
        if(k == 0) ans++;
        else if(k == 1) { cin>>t1; singles.push_back(t1); si.insert(t1); }
        else{
            cin>>t1;
            si.insert(t1);
            for(int j=0; j<k-1; j++){
                cin>>t2;
                si.insert(t2);
                gph[t1][t2] = true;
                gph[t2][t1] = true;
                t1 = t2;
            }
        }
    }
    for(int i=0; i<m+1; i++){
        if(!visited[i] && si.find(i) != si.end()) {
            dfs(i, m+1);
            cc++;
        }
    }
    if(cc != 0) ans+=cc-1;
    for(int sing: singles){
        if(si.find(sing) == si.end()) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
