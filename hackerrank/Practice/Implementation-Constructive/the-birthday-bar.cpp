#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, ans=0, m, d; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>d>>m;
    vector<int> v;
    int sum=0;
    for(int i=0; i<m; i++){
        sum+=a[i];
    }
    v.push_back(sum);
    for(int i=m; i<n; i++){
        sum = sum + a[i] - a[i-m];
        v.push_back(sum);
    }
    for(int z : v){
        if(z == d) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
