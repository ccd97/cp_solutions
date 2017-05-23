#include <bits/stdc++.h>

using namespace std;

int count(int k, int n, int d, bool dused = false) {
    if (n == 0) return dused?1:0;
    if (n < 0) return 0;
    if (k <=0 && n >= 1) return 0;
    return count(k-1, n, d, dused || (k-1>=d)) + count(k, n-k, d, dused || (k>=d));
}

int main(int argc, char const *argv[]) {
    int n, k, d; cin>>n>>k>>d;
    int ans = count(k, n, d);
    cout<<ans<<endl;
    return 0;
}
