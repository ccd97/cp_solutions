#include <bits/stdc++.h>

using namespace std;

#define MAX 1000006

bool prime[1000007];

void SieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=MAX; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=MAX; i += p)
                prime[i] = false;
        }
    }
}

int nod(int x) {
    x = abs(x);
    return (x < 10 ? 1 : (x < 100 ? 2 : (x < 1000 ? 3 :
        (x < 10000 ? 4 : (x < 100000 ? 5 : (x < 1000000 ? 6 : 7
        ))))));
}

auto circularPrimes(int n){
    unordered_set<int> cpri;
    for(int i=2; i<MAX; i++){
        if(!prime[i]) continue;
        if(cpri.find(i) != cpri.end()) continue;
        vector<int> cprivec;
        int digits = nod(i), num = i;
        for(int i=0; i<digits; i++){
            int pw = pow(10, digits-1);
            int ld = num / pw;
            num = (num - ld * pw) * 10;
            num += ld;
            if(prime[num]) cprivec.push_back(num);
            else break;
        }
        if(cprivec.size() == digits){
            for(auto cp : cprivec) cpri.insert(cp);
        }
    }
    unsigned long long sum = 0;
    for(auto cp: cpri){
        if(cp < n) sum += cp;
    }
    return sum;
}

int main() {
    SieveOfEratosthenes();
    int n; cin>>n;
    cout<<circularPrimes(n)<<endl;
    return 0;
}
