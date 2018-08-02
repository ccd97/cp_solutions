#include <bits/stdc++.h>

using namespace std;

long long a[100005];
long long cs[100005];
long long mx[100005];

int getFloor(int i, int l, int r, long k){
    long long val;
    int m, idx = -1;
    while(l <= r){
        m = l + (r-l)/2;
        val = mx[m+1]*(m-i+1) - (cs[m+1] - cs[i]);
        if(k < val) r = m - 1;
        else{
            idx = m;
            l = m + 1;
        }
    }
    return idx;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cs[0] = 0; mx[0] = LONG_LONG_MIN;

    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++) cs[i+1] = cs[i] + a[i];
    for(int i=0; i<n; i++) mx[i+1] = max(mx[i], a[i]);
    long long maxsz = 0;
    long long maxszno = 0;
    for(int j, i=0; i<n; i++){
        j = getFloor(i, i, n-1, k);
        if(maxsz < j-i+1){
            maxsz = j-i+1;
            maxszno = mx[j+1];
        }
    }
    cout<<maxsz<<" "<<maxszno<<endl;
    return 0;
}
