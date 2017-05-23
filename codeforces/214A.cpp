#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int m, n; cin>>n>>m;
    int mx = 1005;
    int ans = 0;
    for(int i=0; i<mx; i++){
        for(int j=0; j<mx; j++){
            if(i*i + j == n && i + j*j == m) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
