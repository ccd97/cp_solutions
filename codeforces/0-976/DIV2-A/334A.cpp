#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int p1=1, p2=n*n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            cout<<p1++<<" ";
        }
        for(int j=0; j<n/2; j++){
            cout<<p2--<<" ";
        }
        cout<<endl;
    }
    return 0;
}
