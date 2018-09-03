#include <iostream>
int main() {
    int t,j;
    std::cin>>t;
    while(t--){
        unsigned long long int a,b,c;
        std::cin>>a;
        for(j=0;a!=1;j++){
            if((a & (a-1)) == 0) a = a>>1;
            else{
                for(b=1;b<a && b!=0;b=b<<1) c=b;
                a -= c;
            }
        }
        if(j%2 ==0) std::cout<<"Richard"<<std::endl;
        else std::cout<<"Louise"<<std::endl;
    }
}
