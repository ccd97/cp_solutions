#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long a,b,x,y,z; cin>>a>>b>>x>>y>>z;
    long long req_yell = max(0ll, 2*x + y - a);
    long long req_blu = max(0ll, y + 3*z - b);
    cout<<req_yell+req_blu<<endl;
    return 0;
}
