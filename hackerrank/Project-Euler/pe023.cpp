#include <bits/stdc++.h>

using namespace std;

#define LIM 100005
int sod[LIM];

void precomputeSod(){
    memset(sod, 0, sizeof(sod));
    for(int i=1; i<LIM; i++){
        for(int j=i; j<LIM; j+=i){
            sod[j] += i;
        }
    }
    for(int i=1; i<LIM; i++)
        sod[i] -= i;
    sod[1] = 1;
}

int main(int argc, char const *argv[]) {
    precomputeSod();
    unordered_set<int> st;
    for(int i=1; i<LIM; i++){
        if(sod[i] > i) st.insert(i);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n > 28123) cout<<"YES"<<endl;
        else{
            bool succ = false;
            for(auto i : st){
                if(i*i == n) continue;
                if(st.find(n-i) != st.end()){
                    succ = true;
                    break;
                }
            }
            if(succ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
