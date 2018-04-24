#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr + n);
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(i+1 - arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
