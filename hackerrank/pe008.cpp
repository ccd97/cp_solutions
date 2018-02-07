#include <bits/stdc++.h>

using namespace std;

auto solve(string s, int n, int k){
    long long maxp = -1;
    for(int i=0; i<n-k; i++){
        long long p = 1;
        for(int j=0; j<k; j++){
            p *= int(s[j+i]-'0');
        }
        maxp = max(maxp, p);
    }
    return maxp;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        cout<<solve(s, n, k)<<endl;
    }
    return 0;
}
