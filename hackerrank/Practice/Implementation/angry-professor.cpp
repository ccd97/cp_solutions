#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T,N,K,P,i,j;
    cin>>T;
    for(i=0;i<T;i++){
        cin>>N>>K;
        int a[N];
        P=0;
        for(j=0;j<N;j++){
            cin>>a[j];
            if(a[j]<=0) P++;
        }
        if(P>=K) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
