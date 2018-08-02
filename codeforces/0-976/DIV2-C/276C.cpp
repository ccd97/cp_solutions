#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, q, l, r; cin>>n>>q;
    long long arr[n], sec[n+1], cnt[n];
    memset(sec, 0, sizeof(sec));
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n, greater<int>());
    while(q--){
        cin>>l>>r;
        l--;
        sec[l]++, sec[r]--;
    }
    for(int i=0, val=0; i<n; i++){
        val += sec[i];
        cnt[i] = val;
    }
    sort(cnt, cnt+n, greater<int>());
    unsigned long long sum = 0;
    for(int i=0; i<n; i++){
        sum += cnt[i]*arr[i];
    }
    cout<<sum<<endl;
}
