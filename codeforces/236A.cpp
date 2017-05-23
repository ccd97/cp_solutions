#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    string s;
    cin>>s;
    unordered_set<char> set;
    for(char c: s){
        set.insert(c);
    }
    if(set.size() % 2 == 0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}
