#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k; cin>>n>>k;
    if(k > 2*(n-2)) {
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        char gph[4][n];
        for(int i=0; i<n; i++)
            gph[0][i] = gph[1][i] = gph[2][i] = gph[3][i] = '.';
        for(int i=1; i<n/2 and k > 1; i++, k-=2)
            gph[1][i] = gph[1][n-1-i] = '#';
        for(int i=1; i<n/2 and k > 1; i++, k-=2)
            gph[2][i] = gph[2][n-1-i] = '#';
        if(k==2) gph[1][n/2] = gph[2][n/2] = '#';
        if(k==1) gph[1][n/2] = '#';
        cout<<"YES"<<endl;
        for(int i=0; i<4; i++){
            for(int j=0; j<n; j++)
                cout<<gph[i][j];
            cout<<endl;
        }
    }
    return 0;
}
