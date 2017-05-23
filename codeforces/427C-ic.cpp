#include <bits/stdc++.h>

using namespace std;

vector<int> gph[100005];
long long cost[100005];

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>cost[i];
    int m, t1, t2; cin>>m;
    for(int i=0; i<m; i++){
        cin>>t1>>t2; t1--, t2--;
        gph[t1].push_back(t2);
    }
    return 0;
}
