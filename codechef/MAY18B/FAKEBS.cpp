#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n, q; cin>>n>>q;
        long arr[n], sarr[n], x;
        unordered_map<long, int> pmp, spmp;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int i=0; i<n; i++)
            sarr[i] = arr[i];
        sort(sarr, sarr+n);
        for(int i=0; i<n; i++){
            pmp.emplace(arr[i], i);
        }
        for(int i=0; i<n/2; i++){
            spmp.emplace(sarr[i], i);
            spmp.emplace(sarr[n-i-1], i);
        }
        if(n%2) spmp.emplace(sarr[n/2], n/2);
        while(q--){
            int ans, cans = 0, nod = 0, lo=0, hi=n-1, mid;
            cin>>x;
            vector<bool> flips;
            stack<bool> stf;
            vector<long> dips;
            while(lo<=hi){
                mid = (lo + hi)/2;
                if(arr[mid] == x) break;
                else if(arr[mid] < x){
                    if(pmp[x] < mid){
                        hi = mid - 1;
                        flips.push_back(true);
                    }
                    else {
                        lo = mid + 1;
                        dips.push_back(arr[mid]);
                    }
                }
                else{
                    if(pmp[x] > mid){
                        lo = mid + 1;
                        flips.push_back(false);
                    }
                    else {
                        hi = mid - 1;
                        dips.push_back(arr[mid]);
                    }
                }
            }
            for(auto e : flips){
                if(stf.empty()) stf.push(e);
                else if((!stf.top() and e) or (stf.top() and !e)){
                    stf.pop(); cans++;
                }
                else stf.push(e);
            }
            for(int e : dips){
                if(x < sarr[n/2] and e < x) nod++;
                if(x > sarr[n/2] and e > x) nod++;
            }
            ans = flips.size() - cans;
            if(flips.size() - 2*cans + nod > spmp[x])
                cout<<-1<<endl;
            else if(ans <= spmp[x])
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}
