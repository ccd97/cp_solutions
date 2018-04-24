#include <ostream>
#include<iostream>

#define int_declare_cin(x) int x; std::cin>>x
#define for_range(n) for(int i=0; i<n; i++)

int main(){
    int_declare_cin(n);
    while(n--){
        int_declare_cin(l);
        int inp;
        long s1=0, s2=0;
        for_range(l){
            std::cin>>inp;
            i%2==0?s1+=inp:s2+=inp;
        }
        for_range(l){
            std::cin>>inp;
            i%2==0?s2+=inp:s1+=inp;
        }
        std::cout << ((s1>s2)?s2:s1) <<std::endl;
    }
}
