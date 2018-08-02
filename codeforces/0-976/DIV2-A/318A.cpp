#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, k;
    cin>>n>>k; n++;
    if(k <= n/2) cout<<2*k-1<<endl;
    else cout<<2*(k-n/2)<<endl;
    return 0;
}
