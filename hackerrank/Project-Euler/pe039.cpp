#include <bits/stdc++.h>

using namespace std;

vector<int> no_trip(5000006, 0);
vector<int> max_no_trip(5000006, 0);

void gen_pyth_trip(){
    for(int m=1; m<2250; m++){
        for(int n=1; n<m; n++){
            if((m%2 == 1 && n%2 == 1) || __gcd(m,n) != 1)
                continue;
            long peri = 2*m*(m+n);
            for(int k=1; k*peri < 5000006;k++){
                no_trip[k*peri]++;
            }
        }
    }
    int max_c = 0, max_idx = 0;
    for(int i=0; i<5000006; i++){
        if(no_trip[i] > max_c){
            max_c = no_trip[i]; max_idx = i;
        }
        max_no_trip[i] = max_idx;
    }
}

int main(int argc, char const *argv[]) {
    gen_pyth_trip();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<max_no_trip[n]<<endl;
    }
    return 0;
}
