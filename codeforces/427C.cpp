#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

vector<int> gph[100005];
vector<int> gphT[100005];
stack<int> dfsstack;
int ssci[100005];
long long cost[100005];

void dfs(int curr, int cn){
    ssci[curr] = cn;
    for(int i=0; i<gph[curr].size(); i++){
            if(ssci[gph[curr][i]] == -1) dfs(gph[curr][i], cn);
    }
    dfsstack.push(curr);
}

void dfsT(int curr, int cn){
    ssci[curr] = cn;
    for(int i=0; i<gphT[curr].size(); i++){
            if(ssci[gphT[curr][i]] == -1) dfsT(gphT[curr][i], cn);
    }
}

void solve(int n){
    memset(ssci, -1, sizeof(ssci));
    int nscc = 0;
    for(int i=0; i<n; i++){
        if(ssci[i] == -1) dfs(i, nscc++);
    }
    memset(ssci, -1, sizeof(ssci));
    nscc = 0; int didx;
    while(!dfsstack.empty()){
        didx = dfsstack.top();
        dfsstack.pop();
        if(ssci[didx] == -1) dfsT(didx, nscc++);
    }
    int no_scc = *max_element(ssci, ssci+n)+1;
    long minc[no_scc]; int minct[no_scc];
    for(int i=0; i<no_scc; i++) minc[i] = LONG_MAX;
    for(int i=0; i<n; i++){
        if(minc[ssci[i]] == cost[i]){
            minct[ssci[i]]++;
        }
        else if(minc[ssci[i]] > cost[i]){
            minc[ssci[i]] = cost[i];
            minct[ssci[i]] = 1;
        }
    }
    long long mincost = 0;
    long long ways = 1;
    for(int i=0; i<no_scc; i++){
        mincost = (mincost + minc[i]);
        ways = (ways * minct[i])%MOD;
    }
    cout<<mincost<<" "<<ways<<endl;
}

int main(){
    int n; long m, t1, t2; cin>>n;
    for(int i=0; i<n; i++) cin>>cost[i];
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>t1>>t2; t1--, t2--;
        gph[t1].push_back(t2);
        gphT[t2].push_back(t1);
    }
    solve(n);
    return 0;
}
