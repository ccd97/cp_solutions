#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int denom[] = {1, 2, 5, 10, 20, 50, 100, 200};
long long dp[100005][8];


void builddp() {
    for(int i=0; i<8; i++) dp[0][i] = 1;
    for (int i=1; i<=100005; i++) {
        for (int j=0; j<8; j++) {
            dp[i][j] = ((((i-denom[j] >= 0)?dp[i-denom[j]][j]:0)%MOD) + ((j >= 1)?dp[i][j-1]:0)%MOD);
        }
    }
}

int main() {
    builddp();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<(dp[n][7]%MOD)<<endl;
    }
    return 0;
}
