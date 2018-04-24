#include <bits/stdc++.h>

using namespace std;

struct req {
    int i; int c; int p;
    bool operator<(const req& r) const {
        if(p == r.p) return c < r.c;
        else return p > r.p;
    }
};

struct tbls {
    int i; int t; bool v;
    bool operator<(const tbls& r) const {
        return t < r.t;
    }
};

int main(int argc, char const *argv[]) {
    int n, k, tc, tp, tmp; cin>>n;
    req r[n];
    for(int i=0; i<n; i++) {
        cin>>tc>>tp;
        r[i].i = i+1, r[i].c = tc, r[i].p = tp;
    }
    cin>>k;
    tbls t[k];
    for(int i=0; i<k; i++){
        cin>>tmp;
        t[i].i = i+1, t[i].t = tmp, t[i].v = false;
    }
    sort(r, r+n);
    sort(t, t+k);
    vector<pair<int, int>> result;
    long profit = 0;
    for(int i=0; i<n; i++){
        int idx = 0;
        for(; idx<k; idx++){
            if(t[idx].v) continue;
            if(t[idx].t >= r[i].c) break;
        }
        if(idx == k) continue;
        profit += r[i].p;
        result.emplace_back(r[i].i, t[idx].i);
        t[idx].v = true;
    }
    cout<<result.size()<<" "<<profit<<endl;
    for(auto p : result){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
