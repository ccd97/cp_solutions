#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long arr[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        long long sum = 0, imx, lmx = LONG_LONG_MAX;
        for(int i=n-1; i>=0; i--){
            imx = -1;
            for(int j=0; j<n; j++){
                if(arr[i][j] > imx && arr[i][j] < lmx){
                    imx = arr[i][j];
                }
            }
            if (imx == -1){
                sum = -1; break;
            }
            else{
                lmx = imx; sum += imx;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
