#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, p; cin>>n>>p;
    int t1 = p/2;
    if(p % 2 == 1) p--;
    int t2 = (n-p)/2;
    cout<<min(t1, t2)<<endl;
    return 0;
}
