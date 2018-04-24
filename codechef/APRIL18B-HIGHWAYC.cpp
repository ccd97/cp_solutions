#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n, s, y; cin>>n>>s>>y;
        int v[n], c[n]; bool d[n]; long long p[n];
        for(int i=0; i<n; i++) cin>>v[i];
        for(int i=0; i<n; i++) cin>>d[i];
        for(int i=0; i<n; i++) cin>>p[i];
        for(int i=0; i<n; i++) cin>>c[i];
        double trtcl = 1.0*y/s;
        double ttime = 0.0;
        for(int i=0; i<n; i++){
            double trffc = 1.0*(abs(p[i]) - (v[i]*ttime))/v[i];
            double trfbc = 1.0*(abs(p[i]) + c[i] - (v[i]*ttime))/v[i];
            ttime += trtcl;
            if((trfbc < 0.0) || ((p[i]+c[i]) <= 0.0 && !d[i]) || ((p[i]-c[i]) >= 0.0 && d[i]))
                continue;
            if(trffc - trtcl < 1e-6) ttime += trfbc;
        }
        cout<<setprecision(10)<<ttime<<endl;
    }
    return 0;
}
