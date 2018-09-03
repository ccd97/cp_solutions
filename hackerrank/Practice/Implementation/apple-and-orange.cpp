#include<iostream>
#include<algorithm>

#define data_declare_cin(x, type) type x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) data_declare_cin(n, int); while(n--)
#define print_single(a) std::cout<<a<<std::endl
#define array_declare_cin(x, n, type) type x[n]; for(int i=0; i<n; i++){std::cin>>x[i];}

int main(){
    int s,t,a,b,m,n, a_s=0, o_s=0;
    std::cin>>s>>t>>a>>b>>m>>n;
    for_range(i, m){
        data_declare_cin(x, int);
        if(a + x >= s && a + x <= t) a_s++;
    }
    for_range(i, n){
        data_declare_cin(x, int);
        if(b + x >= s && b + x <= t) o_s++;
    }
    print_single(a_s);
    print_single(o_s);
}
