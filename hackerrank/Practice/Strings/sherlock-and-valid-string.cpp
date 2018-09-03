#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    int m[26];
    for(int i=0; i<26; i++) m[i] = 0;
    for(int i=0; i<s.size(); i++){
        m[s[i]-'a']++;
    }
    vector<int> v;
    for(int i=0; i<26; i++){
        if(m[i] != 0){
            if(v.empty() || v.back() != m[i] || v.size() > 1) v.push_back(m[i]);
        }
    }
    if(v.size() > 2) cout<<"NO"<<endl;
    else if(v.size() < 2) cout<<"YES"<<endl;
    else{
        if(abs(v[0] - v[1]) < 2 || v[1] == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
