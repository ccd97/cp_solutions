#include <bits/stdc++.h>

using namespace std;


int get_no_divisors(long long n) {
    long ans = 0;
    for (long i=1; i<=sqrt(n); i++) {
        if (n%i == 0) {
            if (n/i == i) ans++;
            else ans += 2;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    long long n; cin>>n;
    cout<<get_no_divisors(n)<<endl;
    return 0;
}
