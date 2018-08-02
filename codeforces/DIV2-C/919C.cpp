#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m, k; cin>>n>>m>>k;
    unsigned long long ans = 0, unocc = 0;
    bool occ[n][m];
    vector<int> rl, cl;
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ch;
            if(ch == '*'){
                occ[i][j] = true;
            }
            else{
                unocc++;
                occ[i][j] = false;
            }
        }
    }
    for(int i=0; i<n; i++){
        int l = 0;
        for(int j=0; j<m; j++){
            if(occ[i][j]){
                if(l >= k) ans += l-k+1;
                l = 0;
            }
            else l++;
        }
        if(l >= k) ans += l-k+1;
    }
    for(int i=0; i<m; i++){
        int l = 0;
        for(int j=0; j<n; j++){
            if(occ[j][i]){
                if(l >= k) ans += l-k+1;
                l = 0;
            }
            else l++;
        }
        if(l >= k) ans += l-k+1;
    }
    cout<<((k==1)?unocc:ans)<<endl;
    return 0;
}
