#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        unsigned long long ans = 0, a;
        for(int i=0; i<n; i++){
            cin>>a;
            ans ^= (2*a);
        }
        cout<<ans<<endl;
    }
    return 0;
}
