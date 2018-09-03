#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> set;
    string s; cin>>s;
    char prev_char = s[0];
    long long count = 1;
    for(int i=1; i<s.size(); i++){
        set.insert(count * int(prev_char-'a'+1));
        if(prev_char != s[i]){
            prev_char = s[i];
            count = 1;
        }
        else{
            count++;
        }
    }
    set.insert(count * int(prev_char-'a'+1));
    int q; cin>>q;
    while(q--){
        long long qd;
        cin>>qd;
        if(set.find(qd) == set.end()) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
