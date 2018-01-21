#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[]){
	long long n; cin>>n;
	long long dp[n+1]; dp[0] = 1, dp[1] = 0;
	for(int i=2; i<=n; i++){
		dp[i] = ((dp[i-2] * 3)%MOD + (dp[i-1] * 2)%MOD)%MOD;
	}
	cout<<dp[n]%MOD<<endl;
	return 0;
}
