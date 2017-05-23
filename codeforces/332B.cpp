#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin>>n>>k;
    long long a[n], ca[n]; ca[0] = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ca[i+1] = ca[i] + a[i];
    }
    long long as[n] = {0};
    memset(as, 0, sizeof(as));
    for(int i=0; i<n-k+1; i++){
        as[i] = ca[i+k] - ca[i];
    }
    long long maxai[n-k+1] = {0};
    int idx_maxai[n-k+1] = {-1};
    for(int i=0; i<n-k+1; i++){
        if(maxai[i] >= as[i]){
            maxai[i+1] = maxai[i];
            idx_maxai[i+1] = idx_maxai[i];
        }
        else{
            maxai[i+1] = as[i];
            idx_maxai[i+1] = i;
        }
    }
    long long maxi = 0;
    int i1 = -1, i2 = -1;
    for(int i=0; i<n-k; i++){
        // cout<<maxai[i+1]<<" "<<as[i+k]<<endl;
        if(maxi < maxai[i+1] + as[i+k]){
            maxi = maxai[i+1] + as[i+k];
            i1 = idx_maxai[i+1] + 1;
            i2 = i + k + 1;
        }
    }
    cout<<i1<<" "<<i2<<endl;
    return 0;
}
