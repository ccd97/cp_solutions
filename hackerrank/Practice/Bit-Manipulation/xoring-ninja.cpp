#include <iostream>
using namespace std;
#define tc(t) int t; cin>>t; while (t--)
#define ans(a) cout<<a<<endl
typedef unsigned long long int ulli;

int main() {
    ulli max = 1000000007;
    tc(t) {
        int n,a;
        ulli orp = 0;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>a;
            orp |= a;
        }
        for(int i=0;i<n-1;i++) {
            orp = orp << 1;
            if (orp > max) orp %= max;
        }
        ans(orp);
    }
    return 0;
}
