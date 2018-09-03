#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k,i;
    string s,out="";
    cin >> n >> s >> k;
    for(i=0;i<s.length();i++){
        char org = s.at(i);
        int enc = org;
        if((org<65 || org>90)&&(org<97 || org>122)) goto label;
        k%=26;
        enc = org+k;
        if((org<=90 && enc>90)||(org<=122 && enc>122)) enc = enc-26;
        label: out= out + (char)enc;
    }
    cout<<out<<endl;
    return 0;
}
