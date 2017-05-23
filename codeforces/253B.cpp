#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = INT_MAX;
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        auto it = lower_bound(arr+i, arr+n, arr[i]*2);
        if(*it == arr[i]*2) it = lower_bound(arr+i, arr+n, arr[i]*2+1);
        it--;
        ans = min(ans, n - (int)(it-arr - i + 1));
    }
    cout<<ans<<endl;
    return 0;
}
