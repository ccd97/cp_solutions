#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k; cin>>n>>k;
    int p[n], gp[256];
    memset(gp, -1, sizeof(gp));
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++){
        if(gp[p[i]] == -1){
            for(int j=max(0, p[i]-k+1); j<=p[i]; j++){
                if(gp[j]==-1 or gp[j]==j){
                    for(int l=j; l<=p[i]; l++)
                        gp[l]=j;
                    break;
                }
            }
        }
        cout<<gp[p[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
