#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,count,smallest,largest=0;
    cin >> n;
    int a[n];
    for(i = 0;i < n;i++){
       cin >> a[i];
        if(largest<a[i]) largest = a[i];
    }
    cout<<n<<endl;
    while(true){
        smallest = largest;
        for(i=0;i<n;i++){
            if(smallest>a[i] && a[i]>0) smallest = a[i];
        }
        count=0;
        for(i=0;i<n;i++){
            a[i] -= smallest;
            if(a[i]>0) count++;
        }
        if(count==0) break;
        cout<<count<<endl;
    }
    return 0;
}
