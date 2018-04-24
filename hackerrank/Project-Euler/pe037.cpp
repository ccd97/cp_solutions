#include <bits/stdc++.h>

using namespace std;

#define MAX 1000006

bool prime[1000007];

void SieveOfEratosthenes() {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=MAX; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=MAX; i += p)
                prime[i] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
}

int calcTruPri(int num){
    int div = 1, n= num;
    while (n/div >= 10) div *= 10;
    while(n > 0){
        if(!prime[n]) return 0;
        n %= div;
        div /= 10;
    }
    n = num;
    while(n > 0){
        if(!prime[n]) return 0;
        n /= 10;
    }
    return num;
}

int main(int argc, char const *argv[]) {
    SieveOfEratosthenes();
    int n; cin>>n;
    unsigned long long tripsum = 0;
    for(int i=11; i<n; i++){
        if(prime[i]) tripsum += calcTruPri(i);
    }
    cout<<tripsum<<endl;
    return 0;
}
