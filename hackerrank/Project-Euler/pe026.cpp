#include <bits/stdc++.h>

using namespace std;

#define LIM 10004

int nr[LIM];
int mxnr[LIM];

void preComputeRep(){
    nr[1] = 0;
    for(int i=2; i<LIM; i++){
        int rc = 0, idx=1;
        int num = 10;
        unordered_map<int,int> mp;
        while(true){
            if(num % i == 0) break;
            else{
                auto it = mp.find(num % i);
                if(it == mp.end()){
                    mp.emplace(num % i, idx++);
                }
                else{
                    rc = idx - it->second;
                    break;
                }
            }
            num = (num % i) * 10;
        }
        nr[i] = rc;
    }
}

int main(int argc, char const *argv[]) {
    preComputeRep();
    mxnr[0]=0;
    for(int i=1; i<LIM; i++){
        if(nr[mxnr[i-1]] >= nr[i]) mxnr[i] = mxnr[i-1];
        else mxnr[i] = i;
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<mxnr[n-1]<<endl;
    }
    return 0;
}
