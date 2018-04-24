#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, q; cin>>n>>q;
    int arr[n][31];
    int carr[n][31];
    long long tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        for(long long j = 1ll<<30, k=0; j>0; j>>=1){
            arr[i][k++] = (tmp&j)?1:0;
        }
    }
    for(int i=0; i<31; i++) carr[0][i] = arr[0][i];
    for(int i=1; i<n; i++){
        for(int j=0; j<31; j++)
            carr[i][j] = arr[i][j] + carr[i-1][j];
    }
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r; l--, r--;
        long long ans = 0, sumb;
        for(long long i=30, j=1; i>=0; i--, j*=2){
            sumb = (l==0)?carr[r][i]:carr[r][i]-carr[l-1][i];
            if(sumb < (r-l+1)/2 || (sumb == (r-l+1)/2 && (r-l+1)%2!=0)){
                ans += j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
