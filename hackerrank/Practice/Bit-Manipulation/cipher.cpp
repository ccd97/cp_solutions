#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
#define ans(a) cout<<a<<endl
typedef unsigned long long int ulli;

#define bs_limit 1999999

int main() {
    int n,k,l,axb;
    string s;
    cin>>n>>k>>s;
    bitset<bs_limit> ans;
    bitset<bs_limit> enc(s);
    axb = 0, l = 0;
    for(int i=0; i < n; i++) {
        if (k+l == i) {
            axb = axb ^ ans[l];
            l++;
        }
        ans[i] = enc[n+k-2-i] ^ axb;
        axb = axb ^ ans[i];
    }
    s = ans.to_string();
    s = s.substr(bs_limit-n);
    reverse(s.begin(),s.end());
    ans(s);
return 0;
}
