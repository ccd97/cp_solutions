#include <iostream>
#include <bitset>
using namespace std;
#define tc(t) int t; cin>>t; while (t--)
#define ans(a) cout<<a<<endl
typedef unsigned long long int ulli;

int main() {
    tc(t) {
        int i;
        ulli n1,n2;
        cin>>n1>>n2;
        bitset<32> a(n1),b(n2);
        for(i=31; i>=0 ;i--) if(a[i]!=b[i]) break;
        for(int j=i ; j>=0 ;j--) a[j] = 0;
        ans(a.to_ullong());
    }
    return 0;
}
