#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, tmp; cin>>n;
    int par[n+1];
    bool leaf[n+1];
    memset(leaf, true, sizeof(leaf));
    unordered_map<int, int> mp; mp.emplace(1, 0);
    unordered_set<int> st; st.emplace(1);
    for (int i=2; i<n+1; i++){
        cin>>tmp;
        mp[tmp]++;
        mp.emplace(i, 0);
        par[i] = tmp;
        leaf[tmp] = false;
        if(st.find(tmp) == st.end()){
            mp[par[tmp]]--;
            st.emplace(tmp);
        }
    }
    bool succ = true;
    for(int i=1; i<n+1; i++){
        if(!leaf[i] && mp[i] < 3){
            succ = false;
            break;
        }
    }
    if(succ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
