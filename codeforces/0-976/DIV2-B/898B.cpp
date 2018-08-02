#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, a ,b; cin>>n>>a>>b;
    for(int i=0; i<10000000; i++){
        if((n - i*a) % b == 0){
            cout<<"YES"<<endl;
            cout<<i<<" "<<((n-i*a)/b)<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
