#include <bits/stdc++.h>

using namespace std;

#define NOB 20

struct Trie {
    Trie* ch[2] = {nullptr, nullptr};
};

Trie* trie = new Trie;

void insert(int num){
    Trie* ctrie = trie;
    for(int k=NOB; k>=0; k--){
        int bit = (num&(1<<k))>>k;
        if(ctrie->ch[bit] == nullptr){
            ctrie->ch[bit] = new Trie;
        }
        ctrie = ctrie->ch[bit];
    }
}

int query(int xun){
    int ans = 0;

    Trie* ctrie = trie;
    for(int k=NOB; k>=0; k--){
        int bit = (xun&(1<<k))>>k;
        if(ctrie->ch[bit]!=nullptr){
            ctrie = ctrie->ch[bit];
            ans = (ans<<1);
        }
        else {
            ctrie = ctrie->ch[!bit];
            ans = (ans<<1) + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n, m, num; cin>>n>>m;
    unordered_set<int> arr_num;
    while(n--){
        cin>>num;
        arr_num.insert(num);
    }
    for(int i=0; i<(1<<20); i++){
        if(arr_num.find(i) == arr_num.end())
            insert(i);
    }
    int xun = 0;
    while(m--){
        cin>>num;
        xun ^= num;
        cout<<query(xun)<<endl;
    }
    return 0;
}
