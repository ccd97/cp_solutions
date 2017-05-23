#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, t1; cin>>n;
    long long c[100005], dp[100005];
    memset(c, 0, sizeof(int) * 100005);
    for(int i=0; i<n; i++){
        cin>>t1;
        c[t1]++;
    }
    dp[0] = 0, dp[1] = c[1];
    for(int i=2; i<100005; i++){
        dp[i] = max(dp[i-1], dp[i-2] + c[i] * i);
    }
    cout<<dp[100004]<<endl;
    return 0;
}
