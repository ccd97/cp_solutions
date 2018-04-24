#include <bits/stdc++.h>

using namespace std;

int log4perfect(long n){
    int ans = 0;
    while(n > 0){
        ans++; n>>=2;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long fn; cin>>fn;
    unsigned long long arr[fn];
    for(long i=0; i<fn; i++) cin>>arr[i];
    sort(arr, arr+fn, greater<long long>());
    int n = log4perfect(fn);
    unsigned long long ans = 0;
    for(long i=0, j=1; i<fn; i++){
        if(i == j){
            j*=4;
            n--;
        }
        ans += arr[i] * n;
    }
    cout<<ans<<endl;
    return 0;
}
