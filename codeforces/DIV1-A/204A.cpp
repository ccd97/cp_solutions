#include <bits/stdc++.h>

using namespace std;

auto get_req(auto n){
    if(n < 10)
        return n;
    unsigned long long ans = 9;
    string ns = to_string(n);
    for(int i=0; i<ns.size()-2; i++){
        ans += 9 * powl(10, i);
    }
    int fd = int(ns[0]-'0');
    int ld = int(ns[ns.size()-1]-'0');
    auto mds = (n-(fd*powl(10, ns.size()-1))-ld)/10;
    ans += ((fd-1)*powl(10,ns.size()-2));
    ans += ((ld < fd) ? mds : mds+1);
    return ans;
}

int main(){
    unsigned long long a, b; cin>>a>>b;
    cout<<(get_req(b) - get_req(a-1))<<endl;
    return 0;
}
