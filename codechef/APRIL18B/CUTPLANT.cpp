#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1e5 + 5;

long a[LIMIT];
long b[LIMIT];
int sts[2*LIMIT];
map<long, vector<int>, greater<long>> mp;
int F[18][LIMIT];

inline int applyMin(int i, int j){return a[i]<a[j]?i:j;}
inline int clz(int x){return __builtin_clz(x);}
inline int lg2(int x){return !x ? -1 : 31 - clz(x);}

void build_stm(int n) {
    for (int i=0; i<n; ++i) F[0][i] = i;
    for (int k=1; (1<<k)<=n; ++k)
        for (int i=0; i+(1<<k)-1<n; ++i)
            F[k][i] = applyMin(F[k - 1][i], F[k - 1][i + (1 << (k - 1))]);
}

int query_stm(int n, int l, int r) {
    if (l == r) return F[0][l];
    int k = lg2(r - l + 1);
    return applyMin(F[k][l], F[k][r - (1 << k) + 1]);
}

void update_sts(int n, int p, int val) {
    sts[p+n] = val;
    for (int i=p+n; i > 1; i >>= 1)
        sts[i>>1] = sts[i] + sts[i^1];
}

int query_sts(int n, int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) res += sts[l++];
        if(r&1) res += sts[--r];
    }
    return res;
}

int solve(int n, int l, int r){
    int ans = 0;
    if(l>r) return ans;
    int minpos = query_stm(n, l ,r);
    int pl = minpos, pr = minpos;
    while(pl >= l and b[pl] <= a[minpos]) pl--;
    while(pr <= r and b[pr] <= a[minpos]) pr++;
    mp.clear();
    for(int i=pl+1; i<pr; i++)
        mp[b[i]].push_back(i);
    for(auto v: mp){
        int ppos = -1;
        for(auto e : v.second){
            if(a[e] == b[e]) continue;
            if(ppos == -1 || query_sts(n, ppos+1, e)) {
                ans++;
            }
            ppos = e;
        }
        for(auto e : v.second) update_sts(n, e, 1);
    }
    for(auto v: mp){
        for(auto e : v.second) update_sts(n, e, 0);
    }
    ans += solve(n, l, pl);
    ans += solve(n, pr, r);
    return ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        bool is_valid = true;
        for(int i=0; i<n; i++)
            if(a[i] < b[i]){
                is_valid = false;
                break;
            }
        if(!is_valid){
            cout<<"-1\n";
            continue;
        }
        build_stm(n);
        cout<<solve(n, 0, n-1)<<"\n";
    }
    return 0;
}
