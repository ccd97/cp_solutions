#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int m, k, u, cs; cin>>m>>k>>u;
    int kb[k], usb[u];
    for(int i=0; i<k; i++) cin>>kb[i];
    for(int i=0; i<u; i++) cin>>usb[i];
    int max = -1;
    for(int i=0; i<k; i++){
        for(int j=0; j<u; j++){
            cs = kb[i] + usb[j];
            if(cs <= m && max < cs) max = cs;
        }
    }
    cout<<max<<endl;
    return 0;
}
