#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    vector<string> ss;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'h'){
            ss.push_back("h");
        }
        else if(s[i] == 'e'){
            for(int i=0; i<ss.size(); i++){
                if(ss[i].back() == 'h') ss[i]+='e';
            }
        }
        else if(s[i] == 'l'){
            for(int i=0; i<ss.size(); i++){
                if(ss[i].back() == 'e') ss[i]+='l';
                else if(ss[i].back() == 'l' && ss[i][ss[i].size()-2] == 'e') ss[i]+='l';
            }
        }
        else if(s[i] == 'o'){
            for(int i=0; i<ss.size(); i++){
                if(ss[i].back() == 'l' && ss[i][ss[i].size()-2] == 'l'){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
