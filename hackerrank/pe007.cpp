#include <bits/stdc++.h>

using namespace std;

vector<int> primesv;

void SieveOfEratosthenes(int n) {
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
    SieveOfEratosthenes(2e6);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<primesv[n-1]<<endl;
    }
    return 0;
}
