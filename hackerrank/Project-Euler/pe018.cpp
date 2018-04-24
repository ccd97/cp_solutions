#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int tri[20][20];
        int dp[20][20];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                cin>>tri[i][j];
            }
        }
        dp[0][0] = tri[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                auto mx = (j==0)?dp[i-1][j]:max(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] = mx + tri[i][j];
            }
        }
        int smx = 0;
        for(int i=0; i<n; i++){
            smx = max(smx, dp[n-1][i]);
        }
        cout<<smx<<endl;
    }
    return 0;
}
