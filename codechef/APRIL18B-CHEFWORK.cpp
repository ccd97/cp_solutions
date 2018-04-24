#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long n, t, m1=INT_MAX, m2=INT_MAX, m3=INT_MAX; cin>>n;
    long c[n];
    for(int i=0; i<n; i++) cin>>c[i];
    for(int i=0; i<n; i++) {
        cin>>t;
        if(t == 1 and c[i] < m1) m1 = c[i];
        else if(t == 2 and c[i] < m2) m2 = c[i];
        else if(t == 3 and c[i] < m3) m3 = c[i];
    }
    cout<<min(m1+m2, m3)<<endl;
    return 0;
}
