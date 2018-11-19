#include <bits/stdc++.h>

using namespace std;

#define MAX 1000006

vector<int> SieveOfEratosthenes() {

    bitset<MAX> not_prime;
    for (int p=2; p*p<=MAX; p++) {
        if (not_prime[p] == 0) {
            for (int i=p*2; i<=MAX; i += p)
                not_prime[i] = 1;
        }
    }

    vector<int> prime_numbers;
    for(int i=2; i<MAX; i++)
        if(not_prime[i] == 0) prime_numbers.push_back(i);

    return prime_numbers;
}

vector<pair<int, int>> PrimeFactors(int num){
    vector<pair<int, int>> prime_factors;

    auto primes = SieveOfEratosthenes();
    for(auto p : primes){
        if(num <= 1) break;
        int mul_count = 0;
        while(num % p == 0){
            mul_count++;
            num /= p;
        }
        if(mul_count > 0)
            prime_factors.emplace_back(p, mul_count);
    }


    return prime_factors;
}

bool check_super_sqrt(int a, int b){
    if(a == b) return true;
    auto sr = sqrt(b);
    if(sr == floor(sr))
        return check_super_sqrt(a, sr);
    else return false;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    auto pf = PrimeFactors(n);
    if(pf.empty())
        pf.emplace_back(1, 1);
    int ans = 1;
    int maxpow = 0, near2p;
    for(auto pfp : pf){
        ans *= pfp.first;
        maxpow = max(maxpow, pfp.second);
    }
    near2p = ceil(log2(maxpow));
    if(!check_super_sqrt(ans, n))
        near2p++;
    cout<<ans<<" "<<near2p<<endl;
    return 0;
}
