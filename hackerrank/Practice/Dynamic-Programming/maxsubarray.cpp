#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define ans(a) cout<<a<<endl
#define tc(t) int t; cin>>t; while (t--)
typedef unsigned long long int ulli;

int main() {
    tc(t){
        int n,max_tmp,max_sc=0,max_snc=0,lmax=INT_MIN;
        cin>>n;
        int a[n];
        for(int i=0; i<n ;i++) cin>>a[i];
        max_sc = max_tmp = a[0];
        if(a[0]>0) max_snc = a[0];
        if(a[0]>lmax) lmax = a[0];
        for(int i=1 ;i<n ;i++) {
            max_tmp = max(a[i],max_tmp+a[i]);
            max_sc = max(max_sc,max_tmp);
            if(a[i]>0) max_snc+= a[i];
            if(lmax<a[i]) lmax = a[i];
        }
        cout<<max_sc<<" "<<((max_snc==0)?lmax:max_snc)<<endl;
    }
    return 0;
}
