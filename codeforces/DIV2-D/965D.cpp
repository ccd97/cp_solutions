#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int w, l, tmp; cin>>w>>l;
    long long ans = LLONG_MAX;
    long long carr[w]; carr[0] = 0;
    for(int i=0; i<w-1; i++){
        cin>>tmp;
        carr[i+1] = carr[i] + tmp;
    }
    for(int i=0; i<w-l; i++){
        ans = min(ans, carr[i+l]-carr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
