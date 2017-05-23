#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int t1, t2, t3, xt = 0, yt = 0, zt = 0;
    for(int i=0; i<n; i++){
        cin>>t1>>t2>>t3;
        xt += t1, yt += t2, zt += t3;
    }
    if(xt == 0 && yt == 0 && zt == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
