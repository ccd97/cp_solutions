#include <bits/stdc++.h>

using namespace std;

unsigned long long phash[1000005];
// unsigned long long shash[1000005];
unsigned long long power[1000005];

struct string_hash{
    unsigned long long prime = 1000000009;

    string_hash(string s){
        long n = s.size();
        power[0] = 1, phash[0] = 0;
        // shash[0] = 0;
        for(int i=0; i<=n; i++){
            power[i+1] = power[i] * prime;
            phash[i+1] = phash[i] * prime + s[i];
            // shash[i+1] = shash[i] * prime + s[n-1-i];
        }
    }

    auto hash(long s, long e){
        return phash[e+1] - phash[s] * power[e-s+1];
    }

    // auto rhash(long s, long e){
    //     return shash[e+1] - shash[s] * power[e-s+1];
    // }

};

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    long n = s.size();
    auto sh = string_hash(s);
    for(long i=n-2; i>=0; i--){
        auto h1 = sh.hash(0, i);
        auto h2 = sh.hash(n-i-1, n-1);
        if(h1 == h2){
            for(long j=1; j<n-i-1; j++){
                if(sh.hash(j, j+i) == h1){
                    cout<<s.substr(j, i+1)<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Just a legend"<<endl;
    return 0;
}
