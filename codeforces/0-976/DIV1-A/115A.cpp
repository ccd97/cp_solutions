#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int p[n];
    bool vi[n];
    for(int i=0; i<n; i++) {
        cin>>p[i];
        if(p[i] != -1) p[i]--;
        vi[i] = false;
    }
    int ans = 0;
    unordered_set<int> par = {-1};
    while(true){
        bool allvisited = true;
        for(int i=0; i<n; i++){
            if(!vi[i]) allvisited = false;
        }
        if(allvisited) break;
        unordered_set<int> npar;
        for(int se : par){
            for(int i=0; i<n; i++){
                if(p[i] == se){
                    npar.insert(i);
                    vi[i] = true;
                }
            }
        }
        par = npar;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
