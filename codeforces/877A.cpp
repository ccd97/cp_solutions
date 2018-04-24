#include <bits/stdc++.h>

using namespace std;

bool checkName(string s){
    bool found = false;
    vector<string> ptns = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    for(string pattern: ptns){
        auto p = s.find(pattern);
        if(p != string::npos){
            if(found) return false;
            found = true;
            auto q = s.find(pattern, p+1);
            if(q != string::npos) return false;
        }
    }
    return found;
}

int main(int argc, char const *argv[]) {
    string s;
    cin>>s;
    if(checkName(s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
