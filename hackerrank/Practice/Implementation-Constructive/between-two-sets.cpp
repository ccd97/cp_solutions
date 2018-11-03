#include<iostream>
#include<algorithm>
#include<functional>

#define data_declare_cin(x, type) type x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) data_declare_cin(n, int); while(n--)
#define print_single(a) std::cout<<a<<std::endl
#define array_declare_cin(x, n, type) type x[n]; for(int i=0; i<n; i++){std::cin>>x[i];}

int n_gcd(int *a, int n){
    std::function<int(int,int)> gcd;
    gcd = [&gcd](int a, int b)->int{
        if(b == 0) return a;
        else return gcd(b, a % b);
    };

    int hcf = a[n-1];
    for_range(i, n-1)
        hcf = gcd(hcf, a[i]);

    return hcf;
}

int n_lcm(int *a, int n){
    std::function<int(int,int)> gcd;
    gcd = [&gcd](int a, int b)->int{
        if(b == 0) return a;
        else return gcd(b, a % b);
    };

    int lcm = a[n-1];
    for_range(i, n-1)
        lcm = lcm*a[i] / gcd(lcm, a[i]);

    return lcm;
}

int main(){
    data_declare_cin(n ,int);
    data_declare_cin(m, int);
    array_declare_cin(a, n, int);
    array_declare_cin(b, m, int);
    int lcm = n_lcm(a, n);
    int gcd = n_gcd(b, m);
    int new_lcm = lcm;
    int count = 0;
    while(new_lcm <= gcd){
        if(gcd % new_lcm == 0) count++;
        new_lcm += lcm;
    }
    print_single(count);
}
