#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        long n, h, tmp, mx=0; cin>>n>>h;
        long arr[n];
        for(int i=0; i<n; i++) {
            cin>>tmp; mx = max(mx, tmp);
            arr[i] = tmp;
        }
        long lo = 1, hi = mx, mid, bh, k=mx;
        while(lo <= hi){
            mid = (lo + hi)/2;
            bh = 0;
            for(int i=0; i<n; i++)
                bh += ceil(1.0*arr[i]/mid);
            if(bh <= h){
                k = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        cout<<k<<endl;
    }
    return 0;
}
 
// 3 3 3 1 2 3 3 4 1 2 3 4 5 4 3 2 7
