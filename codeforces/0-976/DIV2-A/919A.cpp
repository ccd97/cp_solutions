#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m; cin>>n>>m;
    double a, b; cin>>a>>b;
    double minans = 1.0 * a/b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        minans = min(minans, 1.0*a/b);
    }
    cout.precision(10);
    cout<<m*minans<<endl;
    return 0;
}
