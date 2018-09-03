#include <iostream>
#define testcase(x) int x;std::cin>>x;
#define printAns(x) std::cout<<x<<std::endl;
int main() {
    testcase(t);
    while(t--){
        int n,x=0;
        std::cin>>n;
        int a[n];
        for(int i=0;i<n;i++) std::cin>>a[i];
        if(n%2==0) goto label;
        for(int i=0;i<n;i+=2) x^=a[i];
        label: printAns(x);
    }
}
