#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, x, y; cin>>n>>x>>y;
    n /= 2;
    if((x==n or x==n+1) and (y==n or y==n+1))
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
