#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    string s;
    cin>>s;

    int flag = 1;
    bool middle = false;
    int a[26];
    for(int i =0 ;i<26;i++){
        a[i] = 0;
    }
    for(int i=0;i<s.length();i++){
        int b =(int) s.at(i) - 97;
        a[b]++;
    }
    for(int i=0;i<26;i++){
        if(a[i]%2!=0){
            if(middle){
                flag=0;
                break;
            }
            middle = true;
        }
    }

    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
