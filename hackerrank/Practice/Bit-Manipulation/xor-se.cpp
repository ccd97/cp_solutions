#include <iostream>

using namespace std;

long long int getn(long long int n){
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    while(n--){
        long long int res = 0;
        long long int l, r;
        cin>>l>>r;
        long long int n = getn(l);
        while(n % 4 != 0 || n == 0){
            res ^= n; l++;
            n =  getn(l);
        }
        long long rm = r-(r-l)%8;
        for(; rm<=r; rm++){
            res ^= getn(rm);
        }
        cout<<res<<endl;
    }
    return 0;
}
