#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n; cin>>n;
    long long ans = -1;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            ans = (n-i)/2 + 1;
            break;
        }
    }
    if(ans == -1) cout<<1<<endl;
    else cout<<ans<<endl;
    return 0;
}
