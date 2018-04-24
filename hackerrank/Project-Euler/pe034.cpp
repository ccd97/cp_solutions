#include <bits/stdc++.h>
using namespace std;

long facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

unsigned long long isCurious(int num){
    int n = num;
    unsigned long long sum = 0;
    while(n > 0){
        sum += facts[n%10];
        n /= 10;
    }
    return (sum%num==0)?num:0;
}

int main() {
    int n; cin>>n;
    unsigned long long ans = 0;
    for(int i=10; i<n; i++){
        ans += isCurious(i);
    }
    cout<<ans<<endl;
    return 0;
}
