#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    unsigned int a[n+1], lap[n][n];
    a[0] = 0;
    for(int i=0; i<n; i++){
        cin>>a[i+1];
    }
    memset(lap, 0, sizeof(lap));
    unsigned int prev, ans = 0;
    for(int i=1; i<=n; i++){
        prev = 0;
        for(int j=0; j<i; j++){
            lap[i][j] = lap[j][prev] + 1;
            if(a[i] == a[j]) prev = j;
            ans = max(ans, lap[i][j]);
        }
    }
    cout<<ans<<endl;
}
