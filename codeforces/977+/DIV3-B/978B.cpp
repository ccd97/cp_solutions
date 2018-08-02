#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    string s; cin>>s;
    vector<pair<char,int>> cc;
    for(int i=0; i<s.size(); i++)
        if(cc.empty() or cc.back().first != s[i])
            cc.emplace_back(s[i], 1);
        else
            cc.back().second++;
    int ans = 0;
    for(auto p : cc)
        if(p.first == 'x' and p.second > 2)
            ans += p.second - 2;
    cout<<ans<<endl;
    return 0;
}
