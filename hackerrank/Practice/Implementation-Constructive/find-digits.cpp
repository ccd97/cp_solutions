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
        int N,n,temp,digit=0;
        cin>>N;
        temp=N;
        while(temp>0){
            n=temp%10;
            temp /= 10;
            if(n!=0 && N%n==0) digit++;
        }
        cout<<digit<<endl;
    }
    return 0;
}
