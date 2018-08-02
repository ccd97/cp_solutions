#include <bits/stdc++.h>

using namespace std;

struct operation{
    int l;
    int r;
    int d;
};

constexpr int N = 1e5 + 5;
long long st[2*N];
long long st2[2*N];

void modify(int n, int l, int r, long long value) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) st[l++] += value;
        if (r&1) st[--r] += value;
    }
}

void modify2(int n, int l, int r, long long value) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) st2[l++] += value;
        if (r&1) st2[--r] += value;
    }
}

long long query(int n, int p) {
    long long res = 0;
    for (p += n; p > 0; p >>= 1) res += st[p];
    return res;
}

long long query2(int n, int p) {
    long long res = 0;
    for (p += n; p > 0; p >>= 1) res += st2[p];
    return res;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k, t1, t2; cin>>n>>m>>k;
    memset(st, 0, sizeof(long long) * n+1);
    memset(st2, 0, 2 * sizeof(long long) * m+1);
    for(int i=0; i<n; i++) cin>>st[n+i];
    operation op[m];
    for(int i=0; i<m; i++){
        cin>>op[i].l>>op[i].r>>op[i].d;
        op[i].l--;
        op[i].r--;
    }
    for(int i=0; i<k; i++){
        cin>>t1>>t2;
        modify2(m, t1-1, t2, 1);
    }
    for(int i=0; i<m; i++){
        t1 = query2(m, i);
        if(t1 > 0){
            modify(n, op[i].l, op[i].r+1, op[i].d * t1);
        }
    }
    for(int i=0; i<n; i++){
        cout<<query(n, i)<<" ";
    }
    cout<<endl;
    return 0;
}
