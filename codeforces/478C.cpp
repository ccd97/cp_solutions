#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long b[3]; cin>>b[0]>>b[1]>>b[2];
    sort(b, b+3);
    if(b[0]+b[1]<=b[2]/2){
        cout<<b[0]+b[1]<<endl;
    }
    else {
        cout<<(b[0] + b[1] + b[2])/3<<endl;
    }
    return 0;
}
