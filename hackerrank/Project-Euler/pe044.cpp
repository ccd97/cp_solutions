#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_set<long long> pent_num;
    vector<long long> pent_num_vec = {-1};
    long long pn, p1, p2, n, k; cin>>n>>k;
    for(long long i=1; i<=n; i++){
        pn = i*(3*i-1)/2;
        pent_num_vec.push_back(pn);
        pent_num.insert(pn);
    }
    for(long long i=k+1; i<n; i++){
        p1 = pent_num_vec[i] + pent_num_vec[i-k];
        p2 = pent_num_vec[i] - pent_num_vec[i-k];
        if(pent_num.find(p1) != pent_num.end() || pent_num.find(p2) != pent_num.end()){
            cout<<pent_num_vec[i]<<endl;
        }
    }
    return 0;
}
