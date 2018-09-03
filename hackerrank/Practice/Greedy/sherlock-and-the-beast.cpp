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
        int N,j=0,k=0,x=0,y=0,sum=0;
        cin>>N;
        for(j=0;j*5<=N;j++){
            if((N-5*j)%3==0) k = (N-5*j)/3;
            else continue;
            if (j+k>sum){
                sum = j+k;
                x=j;
                y=k;
            }
        }
        if(x==0 && y==0) cout<<"-1";
        else{
            for(j=0;j<y;j++) cout<<"555";
            for(j=0;j<x;j++) cout<<"33333";
        }
        cout<<endl;
    }
    return 0;
}
