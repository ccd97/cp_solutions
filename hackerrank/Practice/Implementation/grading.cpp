#include<iostream>
#include<algorithm>

#define data_declare_cin(x, type) type x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) data_declare_cin(n, int); while(n--)
#define print_single(a) std::cout<<a<<std::endl
#define array_declare_cin(x, n, type) type x[n]; for(int i=0; i<n; i++){std::cin>>x[i];}

int main(){
    test_cases(n){
        data_declare_cin(g, int);
        if(g < 38) print_single(g);
        else{
            int z = ((((g / 5) + 1)) * 5);
            if(z - g < 3) print_single(z);
            else print_single(g);
        }
    }
}
