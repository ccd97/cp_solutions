#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long pre[10004];
    long long sos = 0;
    long long son = 0;
    for(int i=0; i<10004; i++){
        sos += i*i;
        son += i;
        pre[i] = (son*son) - sos;
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<pre[n]<<endl;
    }
    return 0;
}
