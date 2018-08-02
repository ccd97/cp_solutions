#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

int main(int argc, char const *argv[]) {
    int s, n, t1, t2; cin>>s>>n;
    vector<pair<int,int>> dr;
    for(int i=0; i<n; i++){
        cin>>t1>>t2;
        if(s > t1) s+= t2;
        else dr.emplace_back(t1, t2);
    }
    bool used[dr.size()];
    for(int i=0; i<dr.size(); i++) used[i] = false;
    for(int i=0; i<dr.size(); i++){
        for(int j=0; j<dr.size(); j++){
            if(!used[j] && dr[j].first < s){
                s+= dr[j].second;
                used[j] = true;
                break;
            }
        }
    }
    for(int i=0; i<dr.size(); i++){
        if(!used[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
