#include <bits/stdc++.h>

using namespace std;

struct Trie{
    unordered_map<char, Trie*> ch;
};

Trie* trie = new Trie;

void insert(string s){
    Trie* ctrie = trie;
    for(size_t i=0; i<s.size(); i++){
        auto it = ctrie->ch.find(s[i]);
        if(it == ctrie->ch.end()){
            Trie* ntrie = new Trie;
            ctrie->ch.emplace(s[i], ntrie);
        }
        ctrie = ctrie->ch[s[i]];
    }
}

int minimax(Trie* ctrie, bool isMax, bool rev){
    if(ctrie->ch.empty()){
        if(rev)
            if(isMax) return 1;
            else return -1;
        else
            if(isMax) return -1;
            else return 1;
    }
    if(isMax){
        int mx = -1;
        for(auto pr: ctrie->ch){
            mx = max(mx, minimax(pr.second, !isMax, rev));
        }
        return mx;
    }
    else{
        int mn = 1;
        for(auto pr: ctrie->ch){
            mn = min(mn, minimax(pr.second, !isMax, rev));
        }
        return mn;
    }
}

void solve(long k){
    bool winposs = minimax(trie, true, false) == 1;
    bool lossposs = minimax(trie, true, true) == 1;
    if(!winposs) cout<<"Second"<<endl;
    else if(winposs and lossposs) cout<<"First"<<endl;
    else if(k%2) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}

int main(int argc, char const *argv[]) {
    long n, k; cin>>n>>k;
    string s;
    while(n--){
        cin>>s;
        insert(s);
    }
    solve(k);
    return 0;
}
