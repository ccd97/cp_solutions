#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,i,n,c,m;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>c>>m;
        int a = n/c;
        int w = a;
        while(true){
            if(w<m) break;
            w-=m;
            w++;
            a++;
        }
        cout<<a<<endl;
    }
    return 0;
}
