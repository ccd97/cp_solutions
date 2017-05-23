#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, t1; cin>>n;
    long sod = 0;
    int d[10]; memset(d, 0, sizeof(int) * 10);
    for(int i=0; i<n; i++){
        cin>>t1;
        d[t1]++;
        sod += t1;
    }
    bool possible = true;
    while(sod%3 != 0){
        bool brk = false;
        for(int i=0; i<9; i+=3){
            if(d[sod%3+i] > 0){
                d[sod%3+i]--;
                sod-=(sod%3+i);
                brk = true;
                break;
            }
        }
        if(!brk){
            for(int i=(sod%3==1)?2:1; i<9; i+=3){
                if(d[i] > 0){
                    d[i]--;
                    sod-=i;
                    brk = true;
                    break;
                }
            }
        }
        if(!brk) {
            possible = false;
            break;
        }
    }
    if(d[0] > 0 && possible){
        if(sod == 0) d[0] = 1;
        for(int i=9; i>=0; i--){
            for(int j=0; j<d[i]; j++){
                cout<<i;
            }
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
