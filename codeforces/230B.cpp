#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    bool prime[1000005];
    memset(prime, true, sizeof(prime));
    for(int i=2; i*i<=1000005; i++){
        if(prime[i]){
            for(int j=i*2; j<1000005; j+=i) prime[j] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
    int n; cin>>n;
    long long int inp;
    for(int i=0; i<n; i++){
        cin>>inp;
        long long sr = round(sqrt(inp));
        if(sr*sr == inp && prime[sr]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
