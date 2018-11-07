#include <bits/stdc++.h>

using namespace std;

#define NOB 30

struct Trie {
    Trie* ch[2] = {nullptr, nullptr};
    Trie* pr = nullptr;
    int cnt = 0;
};

Trie trie;

void insert(long num){
    Trie* ctrie = &trie;
    for(int k=NOB; k>=0; k--){
        int bit = (num&(1<<k))>>k;
        if(ctrie->ch[bit] == nullptr){
            ctrie->ch[bit] = new Trie;
            ctrie->ch[bit]->pr = ctrie;
        }
        ctrie = ctrie->ch[bit];
    }
    ctrie->cnt++;
}

void remove(long num){
    Trie* ctrie = &trie;
    for(int k=NOB; k>=0; k--){
        int bit = (num&(1<<k))>>k;
        ctrie = ctrie->ch[bit];
    }
    ctrie->cnt--;
    while(ctrie->cnt == 0 and ctrie != nullptr){
        if(ctrie->ch[0] != nullptr or ctrie->ch[1] != nullptr) break;
        Trie* ntdel = ctrie;
        ctrie = ctrie->pr;
        if(ctrie->ch[0] == ntdel) ctrie->ch[0] = nullptr;
        if(ctrie->ch[1] == ntdel) ctrie->ch[1] = nullptr;
        delete ntdel;
    }
}

long query(long num){
    long ans = 0;

    Trie* ctrie = &trie;
    for(int k=NOB; k>=0; k--){
        int bit = (num&(1<<k))>>k;
        int xbit = bit^1;
        if(ctrie->ch[xbit] != nullptr){
            ans = (ans<<1) + 1;
            ctrie = ctrie->ch[xbit];
        }
        else{
            ans = (ans<<1);
            ctrie = ctrie->ch[bit];
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    int q; cin>>q;
    char op; long num;
    insert(0);
    while(q--){
        cin>>op>>num;
        switch(op){
            case '+': insert(num); break;
            case '-': remove(num); break;
            case '?': cout<<query(num)<<endl; break;
        }
    }
    return 0;
}
