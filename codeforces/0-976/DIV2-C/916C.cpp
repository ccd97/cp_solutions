#include <bits/stdc++.h>

using namespace std;

bool prime[100005];

void SieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=100005; p++) {
        if (prime[p] == true) {
            for (int i=p*2; i<=100005; i += p)
                prime[i] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    SieveOfEratosthenes();
    int n,m; cin>>n>>m;
    int mc = 0;
    vector<pair<int, int>> gph[n];
    for(int i=0; i<n-2; i++, mc++){
        gph[i].emplace_back(i+1, 1);
    }
    int np = (n==2)?2:mc+1;
    while(!prime[np]) np++;
    gph[n-2].emplace_back(n-1, np - mc);
    mc++;
    for(int i=0; i<n; i++){
        if(mc == m) break;
        for(int j=i+2; j<n; j++){
            if(mc == m) break;
            gph[i].emplace_back(j, np+1);
            mc++;
        }
    }
    cout<<np<<" "<<np<<endl;
    for(int i=0; i<n; i++){
        for(auto p : gph[i]){
            cout<<i+1<<" "<<p.first+1<<" "<<p.second<<endl;
        }
    }
    return 0;
}
