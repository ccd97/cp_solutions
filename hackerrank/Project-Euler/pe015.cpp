#include <bits/stdc++.h>

using namespace std;

#define LIM 505
#define MOD 1000000007

long dp[LIM][LIM];

void dpCompute(){
    for(int i=0; i<LIM; i++) dp[0][i] = 1, dp[i][0] = 1;
    dp[0][0] = 0;
    for(int i=1; i<LIM; i++){
        for(int j=1; j<LIM; j++){
            dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
        }
    }
}

int main(int argc, char const *argv[]) {
    dpCompute();
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
