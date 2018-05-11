#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n], gcd;
        for(int i=0; i<n; i++) cin>>arr[i];
        gcd = arr[0];
        for(int i=1; i<n; i++)
            gcd = __gcd(gcd, arr[i]);
        cout<<(gcd==1?0:-1)<<endl;
    }
    return 0;
}
