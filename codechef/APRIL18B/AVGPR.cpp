#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n,ans=0; cin>>n;
        unordered_set<long> mp;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) mp.insert(a[i]*2);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(mp.find(a[i]+a[j]) != mp.end()) ans++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
