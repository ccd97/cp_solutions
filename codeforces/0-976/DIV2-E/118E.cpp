#include <bits/stdc++.h>

using namespace std;

vector<int> gph[200005];
unordered_set<int> result[200005];

bool visited[200005];
int dist[200005];
int low[200005];

int get_no_of_bridges(int idx, int height, int parent){
    int nob = 0;
    visited[idx] = true;
    height++;
    dist[idx] = height, low[idx] = height;
    for(auto e: gph[idx]){
        if(!visited[e]){
            nob += get_no_of_bridges(e, height, idx);
            low[idx] = min(low[idx], low[e]);
            if(low[e] > dist[idx])
                return 1;
        }
        else if(e != parent){
            low[idx] = min(low[idx], low[e]);
        }
    }
    return nob;
}

int get_no_of_bridges(int n){
    int nob = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            nob += get_no_of_bridges(i, 0, -1);
        }
    }
    return nob;
}

void dfs_path(int idx, int p){
    visited[idx] = true;
    for(auto e: gph[idx]){
        if(!visited[e])
            dfs_path(e, idx);
        if(e != p){
            if(result[e].find(idx) == result[e].end())
                result[idx].insert(e);
        }
    }
}

void dfs_path(int n){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs_path(i, -1);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, m, t1, t2; cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>t1>>t2;
        t1--, t2--;
        gph[t1].push_back(t2);
        gph[t2].push_back(t1);
    }
    memset(visited, false, sizeof visited);
    memset(dist, 0, sizeof dist);
    memset(low, 0, sizeof low);
    int bridges = get_no_of_bridges(n);
    if(bridges > 0){
        cout<<0<<endl;
    }
    else{
        memset(visited, false, sizeof visited);
        dfs_path(n);
        for(int i=0; i<n; i++){
            for(auto e : result[i]){
                cout<<i+1<<" "<<e+1<<endl;
            }
        }
    }
    return 0;
}
