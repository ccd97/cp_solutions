#include <bits/stdc++.h>

using namespace std;

auto maxSubArraySum(long a[], int size) {
    vector<long long> ans(3);
    long long max_so_far = LONG_MIN, max_ending_here = 0;
    for(int k=0; k<3; k++){
        for (int i = k*size; i < (k+1)*size; i++) {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here) max_so_far = max_ending_here;
            if (max_ending_here < 0) max_ending_here = 0;
        }
        ans[k] = max_so_far;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        long t1, arr[3*n];
        long long sum = 0;
        for(int i=0; i<n; i++){
            cin>>t1; arr[i] = t1; arr[n + i] = t1; arr[2*n + i] = t1;
            sum += t1;
        }
        auto maxap = maxSubArraySum(arr, n);
        if(k==1) cout<<maxap[0]<<endl;
        else if(maxap[0] == sum && sum > 0) cout<<sum*k<<endl;
        else if(maxap[1] != maxap[2]) cout<<maxap[1]+(k-2)*(maxap[2] - maxap[1])<<endl;
        else cout<<maxap[2]<<endl;
    }
    return 0;
}
