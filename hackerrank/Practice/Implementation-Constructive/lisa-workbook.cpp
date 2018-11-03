#include <iostream>
using namespace std;

int main() {
    int n,i,j,k,a,count=0,pg=0;
    cin>>n>>k;
    for(i=0; i<n; i++){
        cin>>a;
        pg++;
        for(j=1;j<=a;j++){
            if(j == pg+(j-1)/k){
                count++;
            }
        }
        pg += (a-1)/k;
    }
    cout<<count;
    return 0;
}
