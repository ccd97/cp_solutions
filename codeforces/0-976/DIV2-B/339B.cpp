#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m, tmp; cin>>n>>m;
    int pos = 1;
    long long ans = 0;
    for(int i=0; i<m; i++){
        cin>>tmp;
        if(tmp >= pos){
            ans += tmp - pos;
        }
        else {
            ans += (n - pos) + tmp;
        }
        pos = tmp;
    }
    cout<<ans<<endl;
    return 0;
}
