#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m, t1, t2; cin>>n>>m;
    int a[m+1]; memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++){
        cin>>t1>>t2;
        if(t2 == m) a[t2]++;
        for(int j=t1; j<t2; j++){
            a[j]++;
        }
    }
    bool rechable = true;
    for(int i=0; i<m+1; i++){
        // cout<<a[i]<<" ";
        if(a[i] == 0){
            rechable = false;
            break;
        }
    }
    if(rechable) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
