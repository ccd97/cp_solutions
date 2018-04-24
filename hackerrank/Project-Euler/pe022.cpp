#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    string s, sarr[n];
    unordered_map<string, long long> mp;
    for(int i=0; i<n; i++) cin>>sarr[i];
    sort(sarr, sarr+n);
    for(int i=1; i<=n; i++){
        long long val = 0;
        for(int j=0; j<sarr[i-1].size(); j++){
            val += sarr[i-1][j] - 'A' + 1;
        }
        val *= i;
        mp.emplace(sarr[i-1], val);
    }
    int q; cin>>q;
    while(q--){
        cin>>s;
        cout<<mp[s]<<endl;
    }
    return 0;
}
