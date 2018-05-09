#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n,k; cin>>n>>k;
    int arr[n][n], charr[n][n+1], cvarr[n][n+1], res[n][n];
    string tmp;
    memset(charr, 0, sizeof charr);
    memset(cvarr, 0, sizeof cvarr);
    memset(res, 0, sizeof res);
    for(int i=0; i<n; i++){
        cin>>tmp;
        for(int j=0; j<n; j++)
            arr[i][j] = (tmp[j]=='.')?0:1;
        for(int j=0; j<n; j++)
            charr[i][j+1] = charr[i][j] + arr[i][j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cvarr[i][j+1] = cvarr[i][j] + arr[j][i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=n-k; j++){
            if(charr[i][j+k] - charr[i][j] == 0){
                for(int l=j; l<j+k; l++) res[i][l]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-k; j++){
            if(cvarr[i][j+k] - cvarr[i][j] == 0){
                for(int l=j; l<j+k; l++) res[l][i]++;
            }
        }
    }
    int mi=0,mj=0,mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(res[i][j] > mx){
                mx = res[i][j]; mi = i; mj = j;
            }
        }
    }
    cout<<mi+1<<" "<<mj+1<<endl;
    return 0;
}
