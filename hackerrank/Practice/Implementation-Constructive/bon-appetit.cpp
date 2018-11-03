#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>

#define data_declare_cin(x, type) type x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) data_declare_cin(n, int); while(n--)
#define print_single(a) std::cout<<a<<std::endl
#define array_declare_cin(x, n, type) type x[n]; for(int i=0; i<n; i++){std::cin>>x[i];}

int main(){
    data_declare_cin(n, int);
    data_declare_cin(k, int);
    array_declare_cin(a, n, int);
    data_declare_cin(s, int);
    int a_s = std::accumulate(a, a+n, -a[k]) / 2;
    if(a_s == s) print_single("Bon Appetit");
    else print_single(s-a_s);
}
