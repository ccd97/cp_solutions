#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> gph[100009];
bool visited[100009];
vector<long> ccc;

long dfs(int n, int start){
    if(visited[start]) return 0;
    visited[start] = true;
    long tn = 1;
    for(int i=0; i<gph[start].size(); i++){
        if(!visited[gph[start][i]]){
            tn += dfs(n, gph[start][i]);
        }
    }
    return tn;
}

int main(int argc, char const *argv[]) {
    long n; cin>>n;
    long p; cin>>p;
    long t1, t2;
    long long res = (n*(n-1))/2;
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    for(int i=0; i<p; i++){
        cin>>t1>>t2;
        gph[t1].push_back(t2);
        gph[t2].push_back(t1);
    }
    for(int i=0; i<n; i++){
        t1 = dfs(n, i);
        if(t1 ==0) continue;
        ccc.push_back(t1);
    }
    for(int i=0; i<ccc.size(); i++){
        res -= (ccc[i]*(ccc[i]-1))/2;
    }
    cout<<res<<endl;
    return 0;
}
