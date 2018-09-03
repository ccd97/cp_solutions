#include <iostream>
#include <algorithm>
using namespace std;

struct A{
    int Li;
    int Ti;

    bool operator< (const A& B) const {
        if(B.Ti == Ti){
            return Li < B.Li;
        }
        else return B.Ti < Ti;
    }
};

int main() {
    int n,k,l,t,sum=0,imp=0;
    cin>>n>>k;
    A a[n];
    for(int i=0;i<n;i++){
        cin>>l>>t;
        sum += l;
        if(t == 1) imp++;
        a[i].Li = l;
        a[i].Ti = t;
    }
    sort(a,a+n);
    int los = imp - k;
    for(int i=0;i<los;i++){
        sum -= 2*a[i].Li;
    }
    cout<<sum;
    return 0;
}
