#include <bits/stdc++.h>

using namespace std;

vector<int> primesv;

void SieveOfEratosthenes(int n=500005) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
        if (prime[p]) primesv.push_back(p);
}

int main(int argc, char const *argv[]) {
    SieveOfEratosthenes();
    int t; cin>>t;
    while(t--){
        int n, sr, ans=0; cin>>n;
        for(int pri: primesv){
            if(pri < n){
                sr = round(sqrt(1.0*(n - pri)/2.0));
                if(sr*sr == 1.0*(n-pri)/2.0) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
