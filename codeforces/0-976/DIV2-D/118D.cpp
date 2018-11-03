#include <bits/stdc++.h>

#define MOD  100000000

using namespace std;

int n1, n2, k1, k2;

long dp[102][102][11][11];

int solve(int tn1, int tn2, int ck1, int ck2){
    if(tn1 == n1 and tn2 == n2)
        return 1;
    if(dp[tn1][tn2][ck1][ck2] != -1)
        return dp[tn1][tn2][ck1][ck2];
    int ans = 0;
    if(tn1 < n1 and ck1 < k1)
        ans = (ans+solve(tn1+1, tn2, ck1+1, 0))%MOD;
    if(tn2 < n2 and ck2 < k2)
        ans = (ans+solve(tn1, tn2+1, 0, ck2+1))%MOD;
    dp[tn1][tn2][ck1][ck2] = ans;
    return ans;
}

int main(int argc, char const *argv[]) {
    for(int i=0; i<102; i++)
        for(int j=0; j<102; j++)
            for(int k=0; k<11; k++)
                for(int l=0; l<11; l++)
                    dp[i][j][k][l] = -1;
    cin>>n1>>n2>>k1>>k2;
    cout<<solve(0,0,0,0)<<endl;
    return 0;
}
