#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n, ans=0; cin>>n;
    string s; cin>>s;
    int a[n+2]; a[0] = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'U') a[i+1] = a[i] + 1;
        else if(s[i] == 'D') a[i+1] = a[i] - 1;
    }
    a[n+1] = 0;
    for(int i=1; i<n+1; i++){
        if(a[i+1] == 0 && a[i] < 0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
