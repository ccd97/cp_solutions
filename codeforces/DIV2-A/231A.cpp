#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int t1, t2, t3;
    int ans = 0;
    for(int i=0; i<n; i++){
       cin>>t1>>t2>>t3;
       if(t1+t2+t3 > 1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
