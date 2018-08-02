#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n,m; cin>>n>>m;
    long long a[n], b[m], c[n+1]; c[0] = 0;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=1; i<n+1; i++) c[i] = c[i-1] + a[i-1];
    for(int i=0; i<m; i++){
        int idx = lower_bound(c, c+n+1, b[i]) - c;
        cout<<idx<<" "<<b[i] - c[idx-1]<<endl;
    }
    return 0;
}
