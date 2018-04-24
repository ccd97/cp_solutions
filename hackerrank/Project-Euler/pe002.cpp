#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long int i,t,n,a,b,c,sum;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        sum = 0;
        c = 0;
        a = -1;
        b = 1;
        while(c<n)
        {
            c=a+b;
            a=b;
            b=c;
            if(c%2==0 && c<n)
            {
                sum+=c;
            }
        }
        cout<<sum<<endl;
    }
}
