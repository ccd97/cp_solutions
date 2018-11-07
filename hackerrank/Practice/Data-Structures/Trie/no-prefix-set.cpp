#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie* child[10];
    bool s_end;
    Trie(): s_end(false) {
        for(int i=0; i<10; i++)
            child[i] = nullptr;
    }
};

Trie* trie = new Trie;

bool insert(string s){
    Trie* curr_tp = trie;
    for(size_t i=0; i<s.size(); i++){
        if(curr_tp->child[s[i]-'a'] == nullptr)
            curr_tp->child[s[i]-'a'] = new Trie;
        else
            if(i == s.size()-1) return false;
        curr_tp = curr_tp->child[s[i]-'a'];
        if(curr_tp->s_end) return false;
    }
    curr_tp->s_end = true;
    return true;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    string s, fs;
    bool succ = true;
    for(int i=0; i<n; i++){
        cin>>s;
        if(!succ) continue;
        if(!insert(s)) succ = false, fs = s;
    }
    if(succ) cout<<"GOOD SET"<<endl;
    else cout<<"BAD SET"<<endl<<fs<<endl;
    return 0;
}
