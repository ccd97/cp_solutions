#include <bits/stdc++.h>

using namespace std;

auto gcd(auto a, auto b){
    if(a==0) return b;
    else return gcd(b%a, a);
}

int main(int argc, char const *argv[]) {
    long long dp[41];
    dp[1] = 1;
    for(long long i=2; i<41; i++){
        dp[i] = (dp[i-1] * i) / gcd(dp[i-1], i);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
