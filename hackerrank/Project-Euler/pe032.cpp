#include <bits/stdc++.h>

using namespace std;

auto pdps(vector<int> nos, int a, int b){
    int n1, n2, n3;
    unordered_set<int> pandnum;
    do{
        n1 = 0, n2 = 0, n3 = 0;
        for(int i=0; i<a; i++) n1 = n1*10 + nos[i];
        for(int i=a; i<a+b; i++) n2 = n2*10 + nos[i];
        for(int i=a+b; i<nos.size(); i++) n3 = n3*10 + nos[i];
        if(n1*n2 == n3) pandnum.insert(n3);
    } while(next_permutation(nos.begin(), nos.end()));
    unsigned long long psum = 0;
    for(auto n : pandnum) psum += n;
    return psum;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    vector<int> nos;
    for(int i=1; i<=n; i++){
        nos.push_back(i);
    }
    unsigned long long ans = 0;
    switch(n){
        case 4:
            ans += pdps(nos, 1, 1);
            break;
        case 5:
        case 6:
            ans += pdps(nos, 1, 2);
            break;
        case 7:
        case 8:
            ans += pdps(nos, 1, 3);
            ans += pdps(nos, 2, 2);
            break;
        case 9:
            ans += pdps(nos, 1, 4);
            ans += pdps(nos, 2, 3);
            break;
    }
    cout<<ans<<endl;
    return 0;
}
