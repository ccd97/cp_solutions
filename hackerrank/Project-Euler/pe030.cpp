#include <bits/stdc++.h>

using namespace std;

long pmp[10];

bool issumequal(auto num) {
   long n = num, sum = 0;
   while (n != 0) {
       sum = sum + pmp[n%10];
       if(sum > num) return false;
       n = n/10;
   }
   return sum == num;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    unsigned long long ans = 0;
    for(int i=0; i<10; i++){
        pmp[i] = pow(i, n);
    }
    for(long i=2; i<100000007; i++){
        if(issumequal(i)) ans += i;
    }
    cout<<ans<<endl;
    return 0;
}
