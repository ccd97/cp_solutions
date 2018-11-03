#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        int n,a,b,j,d,e;
        cin>>n>>a>>b;
        d = (n-1)*(a>b?b:a);
        e = abs(a-b);
        for(j=0;j<n;j++){
            cout<<d<<" ";
            if(e == 0) break;
            d += e;
        }
        cout<<endl;
    }
    return 0;
}
