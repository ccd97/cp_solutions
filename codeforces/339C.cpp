#include <bits/stdc++.h>

using namespace std;

bool wp[11];
int M;
vector<int> ans_mat;

void solve(int m, int diff, bool side, int prev){
    if(m==M){
        cout<<"YES"<<endl;
        for(int i=0; i<ans_mat.size(); i++) cout<<ans_mat[i]<<" ";
        cout<<endl;
        exit(0);
    }
    for(int i=1; i<11; i++){
        if(!wp[i] || i == prev) continue;
        if((side && diff < i) || (!side && diff > -i)){
            ans_mat.push_back(i);
            solve(m+1, side?diff-i:diff+i, !side, i);
            ans_mat.pop_back();
        }
    }
}

int main(int argc, char const *argv[]) {
    string s; cin>>s; cin>>M;
    for(int i=1; i<11; i++) wp[i] = s[i-1]=='1';
    solve(0, 0, false, 0);
    cout<<"NO"<<endl;
    return 0;
}
