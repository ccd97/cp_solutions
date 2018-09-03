#include <iostream>
#include <vector>

using namespace std;

bool visited[100000];
vector<int> gph[100005];

long dfs(int n, int start){
    long tn = 0;
    if(visited[start]) return tn;
    visited[start] = true;
    tn++;
    for(int i=0; i<gph[start].size(); i++){
        if(!visited[gph[start][i]]){
            tn += dfs(n, gph[start][i]);
        }
    }
    return tn;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        long m,n,cr,cl,t1,t2, t3,res=0;
        cin>>n>>m>>cl>>cr;
        for(int i=0; i<n; i++)
            gph[i].clear();
        for(int i=0; i<m; i++){
            cin>>t1>>t2;
            gph[t1-1].push_back(t2-1);
            gph[t2-1].push_back(t1-1);
        }
        for(int i=0; i<n; i++) visited[i] = false;
        for(int i=0; i<n; i++){
            t1 = dfs(n, i);
            if(t1 ==0) continue;
            t2 = t1*cl;
            t3 = (t1-1)*cr+cl;
            if(t2 < t3)
                res += t2;
            else
                res += t3;
        }
        cout<<res<<endl;
    }
    return 0;
}
