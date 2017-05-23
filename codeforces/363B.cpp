#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k, t1; cin>>n>>k;
    long long cs[n+1];
    cs[0] = 0;
    for(int i=0; i<n; i++){
        cin>>t1;
        cs[i+1] = cs[i] + t1;
    }
    long long min = LONG_LONG_MAX;
    int idx = -1;
    for(int i=0; i<n-k+1; i++){
        long a1 = cs[i+k] - cs[i];
        if(a1 < min) { min = a1; idx = i+1; }
    }
    cout<<idx<<endl;
    return 0;
}
