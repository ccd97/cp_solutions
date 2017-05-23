#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

bool check(long long k, int a, int b){
    while(k > 0){
        if(k%10 != a && k%10 != b) return false;
        k /= 10;
    }
    return true;
}

unsigned long long divmod(auto n, auto d, auto mod){
    unsigned long long mul;
    while(d != 1){
        mul = mod/d;
        mul++;
        n = (n * mul) % mod;
        d = (d * mul) % mod;
    }
    return n;
}

int main(int argc, char const *argv[]) {
    long a, b ,n; cin>>a>>b>>n;
    if(n == 1) { cout<<2<<endl; return 0; }
    vector<long long> psctrir = {1};
    for(long i=1, k=n; k>0; i++, k--){
        psctrir.push_back((divmod(psctrir.back(), i, MOD) * k) % MOD);
    }
    long long ans = 0;
    int ddiff = abs(a-b);
    for(long long i=0, k=n*min(a, b); i<psctrir.size(); i++, k+=ddiff){
        if(check(k, a, b)) ans = (ans + psctrir[i]) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}
