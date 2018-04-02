#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long sqrtb24ac = round(sqrtl(1 + 8*n));
        if(sqrtb24ac*sqrtb24ac != (1 + 8*n) || (sqrtb24ac-1)%2 != 0){
            cout<<-1<<endl;
            continue;
        }
        cout<<(sqrtb24ac-1)/2<<endl;
    }
    return 0;
}
