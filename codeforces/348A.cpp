#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    long long t1, mx = -1, sum = 0;;
    for(int i=0; i<n; i++){
        cin>>t1;
        sum+=t1;
        mx = max(mx, t1);
    }
    cout<<max(mx, (long long)ceil((double)sum/(n-1)))<<endl;
    return 0;
}
