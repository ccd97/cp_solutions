#include <bits/stdc++.h>

using namespace std;

#define LIM 5000006
long dp[LIM];

long solve(long n) {
  if (n < LIM && dp[n] == -1) {
    dp[n] = 1 + solve((n%2==0)?n/2:3*n+1);
    return dp[n];
  }
  else if(n >= LIM)
    return 1 + solve((n%2==0)?n/2:3*n+1);
  else return dp[n];
}

int main(int argc, char const *argv[]) {
    memset(dp, -1, sizeof(dp)); dp[1] = 1;
    int t; cin>>t;
    vector<long> queries;
    unordered_map<long, long> qans;
    long maxq = 1, mx = 0;
    while(t--) {
        long n; cin>>n;
        maxq = max(maxq, n);
        queries.push_back(n);
        qans[n] = -1;
    }
    for(int i=1; i<=maxq+2; i++){
        if(solve(i) >= dp[mx]) mx = i;
        if(qans.find(i) != qans.end()) qans[i] = mx;
    }
    for(auto q : queries){
        cout<<qans[q]<<endl;
    }
    return 0;
}
