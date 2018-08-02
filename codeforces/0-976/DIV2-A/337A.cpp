#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m; cin>>n>>m;
    int arr[m];
    for(int i=0; i<m; i++) cin>>arr[i];
    sort(arr, arr+m);
    int min = INT_MAX;
    for(int i=0; i<m-n+1; i++){
        if((arr[i+n-1]-arr[i]) < min){
            min = arr[i+n-1] - arr[i];
        }
    }
    cout<<min<<endl;
    return 0;
}
