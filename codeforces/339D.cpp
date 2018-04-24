#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1<<17;
long long st[2*N];

void build(int n){
    for(int i=n; i>0; --i){
        for(int j=(1<<(i-1)); j<(1<<i); ++j){
            if((n-i)% 2 == 0)
                st[j] = st[j<<1] | st[j<<1|1];
            else
                st[j] = st[j<<1] ^ st[j<<1|1];
        }

    }
}

void update(int n, long p, long long value){
    int i=0;
    for (st[p += (1<<n)] = value; p > 1; p >>= 1, i++){
        if(i % 2 == 0)
            st[p>>1] = st[p] | st[p^1];
        else
            st[p>>1] = st[p] ^ st[p^1];
    }
}

int main(int argc, char const *argv[]) {
    int n, m; cin>>n>>m;
    long N = 1ll<<n;
    long long p,b;
    for(long i=0; i<N; i++){
        cin>>st[N+i];
    }
    build(n);
    for(int i=0; i<m; i++){
        cin>>p>>b;
        update(n, p-1, b);
        cout<<st[1]<<endl;
    }
    return 0;
}
