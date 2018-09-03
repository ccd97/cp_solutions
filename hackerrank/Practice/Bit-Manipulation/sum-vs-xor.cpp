#include <iostream>

using namespace std;

int calnoz(long long int n){
    int c = 0;
    while(n > 0){
        if((n&1) == 0) c++;
        n >>= 1;
    }
    return c;
}

int main(int argc, char const *argv[]){
    long long n;
    cin>>n;
    long long nooz = 1ll<<calnoz(n);
    cout<<nooz<<endl;
    return 0;
}
