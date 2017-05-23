#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    int uc=0, lc=0;
    for(char c: s){
        if(c >= 'a' && c<='z') lc++;
        else uc++;
    }
    if(uc > lc) transform(s.begin(), s.end(), s.begin(), ::toupper);
    else transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
    return 0;
}
