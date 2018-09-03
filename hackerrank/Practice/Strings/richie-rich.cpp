#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int half = s.size()/2;
    unordered_set<int> p, p9, p99;
    for(int i=0; i<half; i++){
        if(s[i] != s[s.size()-1-i]){
            if(s[i] == '9') p9.insert(s.size()-1-i);
            else if (s[s.size()-1-i]=='9') p9.insert(i);
            else p.insert(i);
        }
        else if(s[i] == '9' && s[s.size()-1-i] == '9') p99.insert(i);
    }
    if(p.size() + p9.size() > k){cout<<-1<<endl; return 0;}
    for(int i : p9){
        s[i] = '9';
        k--;
    }
    for(int i: p){
        if(s[i] < s[s.size()-1-i]) s[i] = s[s.size()-1-i];
        else s[s.size()-1-i] = s[i];
        k--;
    }
    for(int i=0; i<half; i++){
        if(k>1){
            s[i] = '9'; s[s.size()-1-i] = '9';
            if(p.find(i) != p.end()) k--;
            else if(p9.find(i) == p9.end() && p9.find(s.size()-1-i) == p9.end() && p.find(i) == p.end() && p99.find(i) == p99.end()) k-=2;
        }
        else if(k == 1){
            if(p.find(i) != p.end()){
                s[i] = '9'; s[s.size()-1-i] = '9';
                k--;
            }
        }
    }
    if(k > 0 && s.size()%2==1){
        s[half] = '9'; k--;
    }
    cout<<s<<endl;
    return 0;
}
