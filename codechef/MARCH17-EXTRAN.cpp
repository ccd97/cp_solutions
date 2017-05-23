#include<iostream>
#include<algorithm>

#define int_declare_cin(x) int x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) int_declare_cin(n); while(n--)
#define print_array(a, n) for(int i=0; i<n; i++)std::cout<<a[i]<<"\t"; std::cout<<std::endl
#define print_single(a) std::cout<<a<<std::endl

int main(){
    test_cases(n){
        int_declare_cin(l);
        long a[l];
        bool b[l];
        for_range(i,l){
            std::cin>>a[i];
            b[i] = false;
        }
        std::sort(a,a+l);
        for_range(i ,l-1){
            if(a[i+1]-a[i] != 1){
                if(b[i]) print_single(a[i+1]);
                else print_single(a[i]);
            }
            else{
                b[i] = true;
                b[i+1] = true;
            }
        }
    }
}