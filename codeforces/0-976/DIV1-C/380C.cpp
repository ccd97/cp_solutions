#include <bits/stdc++.h>

using namespace std;

struct brkcnt{
    int opn=0, cls=0, vld=0;
};

constexpr int N = 1<<20;
brkcnt st[2*N];

void init(string s){
    for(size_t i = 0; i<s.size(); i++){
        if(s[i] == '(') st[N+i].opn=1;
        else st[N+i].cls=1;
    }
}

brkcnt combine(brkcnt& l, brkcnt& r){
    int newvld = min(l.opn, r.cls);
    brkcnt parent;
    parent.vld = l.vld + r.vld + newvld;
    parent.opn = l.opn + r.opn - newvld;
    parent.cls = l.cls + r.cls - newvld;
    return parent;
}

void build(){
    for(int i=N-1; i>0; --i){
        st[i] = combine(st[i<<1], st[i<<1|1]);
    }
}

int query(int l, int r){
    brkcnt res, resl, resr;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) resl = combine(resl, st[l++]);
        if (r&1) resr = combine(st[--r], resr);
    }
    res = combine(resl, resr);
    return 2*res.vld;
}

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    memset(st, 0, sizeof(brkcnt)*2*N);
    init(s);
    build();
    int q, l, r; cin>>q;
    while(q--){
        cin>>l>>r; l--;
        cout<<query(l, r)<<endl;
    }
    return 0;
}
