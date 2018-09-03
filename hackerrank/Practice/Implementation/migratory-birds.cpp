#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n,tmp ; cin>>n;
    int b[5];
    for(int i=0; i<5; i++) b[i] = 0;
    for(int i=0; i<n; i++) {
        cin >>tmp;
        b[tmp-1]++;
    }
    int lar = 0;
    int idx = -1;
    for(int i=0; i<5; i++){
        if(b[i] > lar){
            lar = b[i];
            idx = i;
        }
    }
    cout<<idx+1<<endl;
    return 0;
}
