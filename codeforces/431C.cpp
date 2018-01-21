#include <bits/stdc++.h>

using namespace std;
long n, k, d;

#define MOD 1000000007
long dp[1005][2];

// long solve(long currsum, bool isPresent){
// 	if(currsum == n && isPresent) return 1;
// 	long ans = 0;
// 	for(int i=1; i<k+1; i++){
// 		if(currsum + i <= n)
// 			ans += solve(currsum + i, isPresent || i >= d) % MOD;
// 	}
// 	return ans;
// }

long solve(long currsum, bool isPresent){
	if(currsum == n && isPresent) return 1;
	long long ans = 0;
	for(int i=1; i<k+1; i++){
		if(currsum + i <= n){
			if(dp[currsum+i][isPresent || i >= d] == -1){
				dp[currsum+i][isPresent || i >= d] = solve(currsum+i, isPresent || i>=d);
			}
			ans += dp[currsum+i][isPresent || i >= d] % MOD;
		}
	}
	ans %= MOD;
	dp[currsum][isPresent] = ans;
	return ans;
}

int main(){
	cin>>n>>k>>d;
	memset(dp, -1, sizeof(dp));
	cout<<solve(0, false)<<endl;
	// cout<<solve()<<endl;
	return 0;
}
