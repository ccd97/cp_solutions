#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* ch[3] = {nullptr, nullptr, nullptr};
    bool end = false;
};

Trie* trie = new Trie;

void insert(string s){
    Trie* ctrie = trie;
    for(size_t i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        if(ctrie->ch[idx] == nullptr){
            ctrie->ch[idx] = new Trie;
        }
        ctrie = ctrie->ch[idx];
    }
    ctrie->end = true;
}

string curr_str; // for MLE

bool query(Trie* ctrie, size_t sp, char wt){
    if(wt > 1) return false;
    if(ctrie == nullptr) return false;
    if(sp == curr_str.size() and ctrie->end and wt==1) return true;
    return query(ctrie->ch[0], sp+1, wt+((curr_str[sp]!='a')?1:0))
        or query(ctrie->ch[1], sp+1, wt+((curr_str[sp]!='b')?1:0))
        or query(ctrie->ch[2], sp+1, wt+((curr_str[sp]!='c')?1:0));
}

bool query(string s){
    curr_str = s;
    return query(trie->ch[0], 1, ((s[0]!='a')?1:0))
        or query(trie->ch[1], 1, ((s[0]!='b')?1:0))
        or query(trie->ch[2], 1, ((s[0]!='c')?1:0));
}

int main(int argc, char const *argv[]) {
    int n, m; cin>>n>>m;
    string s;
    while(n--){
        cin>>s;
        insert(s);
    }
    while(m--){
        cin>>s;
        cout<<(query(s)?"YES":"NO")<<endl;
    }
    return 0;
}
