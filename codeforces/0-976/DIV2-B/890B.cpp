#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, tmp; cin>>n;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        cin>>tmp;
        m[tmp] = i;
    }
    int lnum = -1;
    int lowest = 300000;
    for(auto p : m){
        if(p.second < lowest){
            lowest = p.second;
            lnum = p.first;
        }
    }
    cout<<lnum<<endl;
    return 0;
}
