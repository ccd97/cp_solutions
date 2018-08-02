#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int k,n,s,p; cin>>k>>n>>s>>p;
    long long ans = ceil(1.0*k/p*ceil(1.0*n/s));
    cout<<ans<<endl;
    return 0;
}
