#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    stack<string> g;
    string tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        if(g.empty()|| (g.top() == "01" && tmp != "01") || (g.top() == "10" && tmp != "10")) g.push(tmp);
    }
    cout<<g.size()<<endl;
    return 0;
}
