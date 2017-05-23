#include <bits/stdc++.h>

using namespace std;

long long get_gcd(long long a, long long b) {
    if (a == 0) return b;
    return get_gcd(b%a, a);
}

int main(int argc, char const *argv[]) {
    vector<long long> factors;
    long long a, b, l, r; cin>>a>>b;
    long long gcd = get_gcd(a, b);
    for(long long i=1; i<=(long long)sqrt(gcd); i++){
        if(gcd % i == 0){
            factors.push_back(i);
            factors.push_back(gcd / i);
        }
    }
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        cin>>l>>r;
        long long max = -1;
        for(unsigned int i=0; i<factors.size(); i++){
            if(factors[i] >= l && factors[i] <= r && factors[i] > max){
                max = factors[i];
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
