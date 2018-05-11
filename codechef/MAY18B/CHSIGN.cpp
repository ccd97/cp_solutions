#include <bits/stdc++.h>

using namespace std;

#define MAX LONG_MAX>>2

long arr[100005];
int btrk[100005][2][2];
long dp[100005][2][2];

long solve(int n, int idx, int ns1, int ns2){
    if(idx >= n+2) return 0;
    long minsum = dp[idx][ns1==-1?0:1][ns2==-1?0:1];
    if(minsum != MAX) return minsum;
    if(arr[idx] + ns1*arr[idx-1] >= 1 and arr[idx] + ns1*arr[idx-1] + ns2*arr[idx-2] >= 1){
        long sm = arr[idx] + solve(n, idx+1, 1, ns1);
        if(minsum > sm){
            minsum = sm;
            btrk[idx][ns1==-1?0:1][ns2==-1?0:1] = 1;
        }
    }
    if(-arr[idx] + ns1*arr[idx-1] >= 1 and -arr[idx] + ns1*arr[idx-1] + ns2*arr[idx-2] >= 1){
        long sm = -arr[idx] + solve(n, idx+1, -1, ns1);
        if(minsum > sm){
            minsum = sm;
            btrk[idx][ns1==-1?0:1][ns2==-1?0:1] = -1;
        }
    }
    dp[idx][ns1==-1?0:1][ns2==-1?0:1] = minsum;
    return minsum;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n; arr[0] = MAX; arr[1] = MAX;
        for(int i=0; i<n; i++) cin>>arr[i+2];
        for(int i=0; i<=n+2; i++)
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = MAX;
        solve(n, 2, 1, 1);
        int sn, s1=1, s2=1;
        for(int i=0; i<n; i++){
            sn = btrk[i+2][s1==-1?0:1][s2==-1?0:1];
            s2 = s1; s1 = sn;
            cout<<sn*arr[i+2]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
