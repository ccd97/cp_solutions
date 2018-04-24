#include <bits/stdc++.h>

using namespace std;

vector<int> primesv;
vector<long long> cps;

void SieveOfEratosthenes(int n=1000006) {
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
    int t; cin>>t;
    SieveOfEratosthenes();
    cps.push_back(0);
    for(int i=0; i<primesv.size(); i++){
        cps.push_back(cps[i] + primesv[i]);
    }
    while(t--){
        int n; cin>>n;
        auto idx = upper_bound(primesv.begin(), primesv.end(), n) - primesv.begin();
        cout<<cps[idx]<<endl;
    }
    return 0;
}
