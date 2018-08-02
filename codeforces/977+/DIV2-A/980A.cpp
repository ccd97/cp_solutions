#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    int cd = 0, co = 0;
    for(auto c : s) (c == '-')?cd++:co++;
    if(co!= 0 and cd % co) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
