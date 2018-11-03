#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, tmp; cin>>n;
    int dec=0, inc=0;
    int hi=-1, lo = -1;
    for(int i=0; i<n; i++){
        cin>>tmp;
        if(hi == -1) hi = tmp;
        else if(tmp > hi){
            hi = tmp;
            inc++;
        }
        if(lo == -1) lo = tmp;
        else if(tmp < lo){
            lo = tmp;
            dec++;
        }
    }
    cout<<inc<<" "<<dec<<endl;
    return 0;
}
