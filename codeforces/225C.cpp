#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
int bc[1005];

int dp[1005][1005][2];

int solve(int col, int colcol, bool lastblack){
    if(col == m && colcol < x) return m*n;
    if(col == m) return 0;
    else if(colcol < x && lastblack){
        if(dp[col+1][colcol+1][true] == -1) dp[col+1][colcol+1][true] = solve(col+1, colcol+1, true);
        dp[col][colcol][lastblack] = (n - bc[col]) + dp[col+1][colcol+1][true];
    }
    else if(colcol < x && !lastblack){
        if(dp[col+1][colcol+1][false] == -1) dp[col+1][colcol+1][false] = solve(col+1, colcol+1, false);
        dp[col][colcol][lastblack] = bc[col] + dp[col+1][colcol+1][false];
    }
    else if(colcol == y && lastblack){
        if(dp[col+1][1][false] == -1) dp[col+1][1][false] = solve(col+1, 1, false);
        dp[col][colcol][lastblack] = bc[col] + dp[col+1][1][false];
    }
    else if(colcol == y && !lastblack){
        if(dp[col+1][1][true] == -1) dp[col+1][1][true] = solve(col+1, 1, true);
        dp[col][colcol][lastblack] = (n - bc[col]) + dp[col+1][1][true];
    }
    else if(colcol >= x && lastblack){
        if(dp[col+1][colcol+1][true] == -1) dp[col+1][colcol+1][true] = solve(col+1, colcol+1, true);
        if(dp[col+1][1][false] == -1) dp[col+1][1][false] = solve(col+1, 1, false);
        dp[col][colcol][lastblack] = min((n - bc[col]) + dp[col+1][colcol+1][true], bc[col] + dp[col+1][1][false]);
    }
    else if(colcol >= x && !lastblack){
        if(dp[col+1][colcol+1][false] == -1) dp[col+1][colcol+1][false] = solve(col+1, colcol+1, false);
        if(dp[col+1][1][true] == -1) dp[col+1][1][true] = solve(col+1, 1, true);
        dp[col][colcol][lastblack] = min((n - bc[col]) + dp[col+1][1][true], bc[col] + dp[col+1][colcol+1][false]);
    }
    return dp[col][colcol][lastblack];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>x>>y;
    memset(bc, 0, sizeof(bc));
    memset(dp, -1, sizeof(dp));
    string r;
    for(int i=0; i<n; i++){
        cin>>r;
        for(int j=0; j<m; j++){
            if(r[j] == '#') bc[j]++;
        }
    }
    cout<<min(m*n, min(solve(0, 0, true), solve(0, 0, false)))<<endl;
    return 0;
}
