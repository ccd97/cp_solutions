#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    long long arr[n];
    int asc[n+1]; asc[0] = 1;
    vector<pair<int, int>> ascidx;
    for(int i=0; i<n; i++) cin>>arr[i];
    if(n < 3){
        cout<<n<<endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        if(arr[i+1] > arr[i]){
            asc[i+1] = asc[i] + 1;
        }
        else{
            ascidx.push_back({i, asc[i]});
            asc[i+1] = 1;
        }
    }
    ascidx.push_back({n-1, asc[n-1]});
    int ans = asc[n-1];
    for(int i=0; i<ascidx.size()-1; i++){
        if((arr[ascidx[i].first + 2] - arr[ascidx[i].first] > 1) || (arr[ascidx[i].first + 1] - arr[ascidx[i].first - 1] > 1)){
            ans = max(ans, ascidx[i].second + ascidx[i+1].second);
        }
        else{
            ans = max(ans, max(ascidx[i+1].second + 1, ascidx[i].second + 1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
