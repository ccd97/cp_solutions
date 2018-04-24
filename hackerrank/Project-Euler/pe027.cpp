#include <bits/stdc++.h>

using namespace std;

#define LIM 100005

bool prime[LIM];

void SieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<LIM; p++) {
        if (prime[p] == true) {
            for (int i=p*2; i<LIM; i += p)
                prime[i] = false;
        }
    }
    prime[0] = false, prime[1] = false;
}

int main(int argc, char const *argv[]) {
    SieveOfEratosthenes();
    int n; cin>>n;
    int mc = 0, ans_a = 0, ans_b = 0;
    for(int a=-n; a<=n; a++){
        for(int b=max(2, -a); b<=n; b++){
            if(!prime[b] || !prime[1+a+b]) continue;
            int c = 0;
            while((c*c+a*c+b > 1) && prime[c*c+a*c+b]) c++;
            if(c > mc){
                mc = c; ans_a = a; ans_b = b;
            }
        }
    }
    cout<<ans_a<<" "<<ans_b<<endl;
    return 0;
}
