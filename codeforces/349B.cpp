#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long n; cin>>n;
    long a[9];
    long mn = LONG_MAX, minidx = -1;
    for(int i=0; i<9; i++){
        cin>>a[i];
        if(a[i] < mn || (a[i] == mn && i > minidx)){
            mn = a[i], minidx = i;
        }
    }
    if(mn > n) {
        cout<<-1<<endl; return 0;
    }
    long d1 = n/mn, n2, d2idx;
    while(n-mn>=0){
        d2idx = -1;
        for(int i=0; i<9; i++){
            n2 = n - a[i];
            if(n2 >= 0 && n2 / mn >= d1-1 && i > d2idx)
                d2idx = i;
        }
        if(d2idx == -1) d2idx = minidx;
        cout<<d2idx+1;
        n-=a[d2idx];
        d1--;
    }
    cout<<endl;
    return 0;
}
