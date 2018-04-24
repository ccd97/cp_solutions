#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin>>s;
    bool startc = false;
    int initz = 0;
    for(int i=0; i< s.size(); i++){
        if(startc && s[i] == '0') initz++;
        if(s[i] == '1') startc = true;
    }
    if(initz >= 6) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
