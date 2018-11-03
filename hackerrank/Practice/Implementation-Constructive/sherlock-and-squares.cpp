#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T,i;
    cin>>T;
    for(i=0;i<T;i++){
        double a1,a2,b1,b2;
        int total;
        cin>>a1>>a2;
        a1=sqrt(a1);
        a2=sqrt(a2);
        b1=floor(a1);
        b2=floor(a2);
        total=abs(b1-b2);
        if(fmod(a1,1) == 0) total++;
        cout<<total<<endl;
    }
    return 0;
}
