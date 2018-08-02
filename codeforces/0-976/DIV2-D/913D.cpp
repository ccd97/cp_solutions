#include <bits/stdc++.h>

using namespace std;

long t;

struct problem {
    int i;
    int a;
    int t;

    bool operator<(const problem& p) const {
        if(t == p.t) return a > p.a;
        else return t < p.t;
    }
};

long calc(auto arr, long m){
    long ans = 0, nt = t;
    for(int i=0; i<arr.size(); i++){
        if(nt < arr[i].t || ans >= m) break;
        if(arr[i].a >= m){
            ans++; nt -= arr[i].t;
        }
    }
    return ans;
}

auto calcidx(auto arr, long m){
    vector<long> idxs;
    for(int i=0; i<arr.size(); i++){
        if(t < arr[i].t || idxs.size() >= m) break;
        if(arr[i].a >= m){
            t -= arr[i].t;
            idxs.push_back(arr[i].i+1);
        }
    }
    return idxs;
}

long binsearch(auto arr, long l, long r){
    long bans = 0;
    while (l <= r) {
        long m = (r+l)/2;
        long ans = calc(arr, m);
        if(ans == m){
            bans = ans;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return bans;
}

int main(int argc, char const *argv[]) {
    long n, ta, tt; cin>>n>>t;
    vector<problem> p(n);
    long maxa = 0;
    for(int i=0; i<n; i++){
        cin>>ta>>tt;
        p[i].i = i; p[i].a = ta; p[i].t = tt;
        maxa = max(maxa, ta);
    }
    sort(p.begin(), p.end());
    auto maxp = binsearch(p, 0, n);
    auto idxs = calcidx(p, maxp);
    cout<<maxp<<endl<<idxs.size()<<endl;
    for(auto i : idxs){
        cout<<i<<" ";
    }
    cout<<endl;
}
