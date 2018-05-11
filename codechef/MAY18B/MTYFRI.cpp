#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n, k, tmp; cin>>n>>k;
        vector<int> mo, po;
        for(int i=0; i<n; i++){
            cin>>tmp;
            if(i%2) po.push_back(tmp);
            else mo.push_back(tmp);
        }
        sort(mo.begin(), mo.end(), greater<int>());
        sort(po.begin(), po.end());

        long long smo=0, spo=0;
        for(auto e : mo) smo += e;
        for(auto e : po) spo += e;

        for(int i=0; i<k; i++){
            if(k >= n-1) break;
            if(po[i] < mo[i]){
                smo -= (mo[i] - po[i]);
                spo += (mo[i] - po[i]);
            }
            if(spo > smo) break;
        }
        if(spo > smo) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
