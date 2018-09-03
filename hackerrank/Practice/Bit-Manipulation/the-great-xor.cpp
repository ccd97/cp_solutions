#include <iostream>

using namespace std;

int noob(long long int n){
    int c = 0;
    while(n > 0){
        c++;
        n >>= 1;
    }
    return c;
}

int main(int argc, char const *argv[]) {
    int q; cin>>q;
    while(q--){
        long long int n;
        cin>>n;
        long long int bs = (1ll << noob(n)) - 1ll;
        cout<<(bs & ~n)<<endl;
    }
    return 0;
}
