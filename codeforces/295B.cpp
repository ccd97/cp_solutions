#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, tmp; cin>>n;
    long long gph[n][n], vo[n], ans[n];
    memset(ans, 0, sizeof(ans));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>gph[i][j];
        }
    }
    for(int i=0; i<n; i++){
        cin>>tmp; vo[n-i-1] = tmp-1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                gph[j][k] = min(gph[j][k], gph[j][vo[i]] + gph[vo[i]][k]);
            }
        }
        for(int j=0; j<=i; j++){
            for(int k=0; k<=i; k++){
                ans[i] += gph[vo[j]][vo[k]];
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[n-i-1]<<" ";
    }
    cout<<endl;
}
