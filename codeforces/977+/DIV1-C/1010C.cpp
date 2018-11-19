#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long a, n, k, smallest_num; cin>>n>>k;
    smallest_num = k;
    for(int i=0; i<n; i++){
        cin>>a;
        smallest_num = __gcd(smallest_num, a%k);
    }
    cout<<floor(k/smallest_num)<<endl;
    for(int i=0; i<k; i+=smallest_num)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
