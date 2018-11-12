#include <bits/stdc++.h>

using namespace std;

struct item{
    int idx, t, d, p;
    item(int idx): idx(idx) {}
};

bool sort_by_d(item const &lhs, item const &rhs){
    return lhs.d < rhs.d;
}

vector<item> arr;
vector<size_t> sol;

int mem_dp[102][3003];

void fill_m1_dp(){
    for(int i=0; i<102; i++)
        for(int j=0; j<3003; j++)
            mem_dp[i][j] = -1;
}

int solve(size_t idx, int etime) {
    int ans = 0;
    if(mem_dp[idx][etime] != -1)
        return mem_dp[idx][etime];
    if(idx >= arr.size())
        ans = 0;
    else if(etime+arr[idx].t >= arr[idx].d)
        ans = solve(idx+1, etime);
    else
        ans = max(arr[idx].p + solve(idx+1, etime+arr[idx].t), solve(idx+1, etime));
    mem_dp[idx][etime] = ans;
    return ans;
}

void backtrack(){
    int res = mem_dp[0][0];
    int t = 0;
    for(size_t i=0; i<arr.size() and res>0; i++){
        if(mem_dp[i+1][t] == -1)
            solve(i+1, t);
        if(res == mem_dp[i+1][t])
            continue;
        else{
            sol.push_back(arr[i].idx);
            res -= arr[i].p;
            t += arr[i].t;
        }
    }
}

int main(int argc, char const *argv[]) {
    fill_m1_dp();
    int n; cin>>n;
    for(int i=0; i<n; i++){
        item itm(i);
        cin>>itm.t>>itm.d>>itm.p;
        arr.push_back(itm);
    }
    sort(arr.begin(), arr.end(), sort_by_d);
    cout<<solve(0, 0)<<endl;
    backtrack();
    cout<<sol.size()<<endl;
    for(auto solidx: sol) cout<<solidx+1<<" ";
    cout<<endl;
    return 0;
}
