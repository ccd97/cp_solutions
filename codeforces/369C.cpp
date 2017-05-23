#include <bits/stdc++.h>

using namespace std;

vector<int> gph[100005];
bool visited[100005];
bool e_has_bad[100005];
int bad_upto_here[100005];

void DFSUtil(int u) {
    bad_upto_here[u] = e_has_bad[u];
    visited[u] = true;
    for (int i=0; i<gph[u].size(); i++)
        if (visited[gph[u][i]] == false){
            DFSUtil(gph[u][i]);
            bad_upto_here[u] += bad_upto_here[gph[u][i]];
        }
}

void DFS(int n) {
    memset(visited, false, sizeof(bool) * n);
    for (int u=0; u<n; u++)
        if (visited[u] == false)
            DFSUtil(u);
}

int main(int argc, char const *argv[]) {
    int n, t1, t2, t3; cin>>n;
    memset(e_has_bad, false, sizeof(bool) * n);
    for(int i=0; i<n-1; i++){
        cin>>t1>>t2>>t3;
        t1--, t2--;
        if(t3 == 2) {
            e_has_bad[t1] = true;
            e_has_bad[t2] = true;
        }
        gph[t1].push_back(t2);
        gph[t2].push_back(t1);
    }
    DFS(n);
    vector<int> cads;
    for(int i=0; i<n; i++){
        if(bad_upto_here[i] == 1 && e_has_bad[i]) cads.push_back(i);
    }
    cout<<cads.size()<<endl;
    for(int i=0; i<cads.size(); i++) cout<<cads[i]+1<<" ";
    cout<<endl;
    return 0;
}
