#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<map>

#define data_declare_cin(x, type) type x; std::cin>>x
#define for_range(i,n) for(int i=0; i<n; i++)
#define test_cases(n) data_declare_cin(n, int); while(n--)
#define print_single(a) std::cout<<a<<std::endl
#define array_declare_cin(x, n, type) type x[n]; for(int i=0; i<n; i++){std::cin>>x[i];}

int main(){
    std::map<int,int> pair_map;
    data_declare_cin(n, int);
    int pairs = 0;
    for_range(i, n){
        data_declare_cin(x, int);
        if(pair_map.find(x) == pair_map.end()) pair_map[x] = 1;
        else pair_map[x]++;
    }
    for(auto it = pair_map.begin(); it != pair_map.end(); ++it)
        pairs += it->second / 2;
    print_single(pairs);
}
