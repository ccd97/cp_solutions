#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    if(s[0] > 'Z'){
        s[0] = 'A' + (s[0] - 'a');
    }
    cout<<s<<endl;
    return 0;
}
