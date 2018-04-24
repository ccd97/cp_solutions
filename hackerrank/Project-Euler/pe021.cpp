#include <bits/stdc++.h>

using namespace std;

#define LIM 100005
int sod[LIM];
int ap[LIM];
long cap[LIM];

void precomputeSod(){
    memset(sod, 0, sizeof(sod));
    memset(ap, 0 , sizeof(ap));
    for(int i=1; i<LIM; i++){
        for(int j=i; j<LIM; j+=i){
            sod[j] += i;
        }
    }
    for(int i=1; i<LIM; i++)
        sod[i] -= i;
    sod[1] = 1;
}

int main(int argc, char const *argv[]) {
    precomputeSod();
    for(int i=1; i<LIM; i++){
        if(sod[i] != i){
            if(sod[i] < LIM && sod[sod[i]] == i){
                ap[sod[i]] = sod[i];
                ap[sod[sod[i]]] = sod[sod[i]];
            }
        }
    }
    cap[0] = 0;
    for(int i=1; i<LIM; i++){
        cap[i] = cap[i-1] + ap[i];
    }
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        cout<<cap[n]<<endl;
    }
    return 0;
}
