#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int l,sum1=0,sum2=0;
        bool suc = false;
        cin>>l;
        int a[l],b[l],c[l];
        for(int j=0;j<l;j++){
            cin>>a[j];
        }

        for(int j=0;j<l;j++){
            sum1 += a[j];
            b[j] =sum1;
        }
        for(int j=l-1;j>=0;j--){
            sum2 += a[j];
            c[j] =sum2;
        }

        for(int j=0;j<l;j++){
            if(b[j]==c[j]){
                suc = true;
                break;
            }
        }
        if(suc) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
