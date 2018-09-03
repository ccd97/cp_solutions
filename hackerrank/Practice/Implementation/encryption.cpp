#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int l,r,c,i;
    cin >> s;
    l = s.length();
    r=floor(sqrt(l));
    c=ceil(sqrt(l));
    string ns = "";
    int j = 0;
    for(i=0;i<c;i++){
        for(j=i;j<l;j+=c){
            ns+=s[j];
        }
        ns+=" ";
    }
    cout<<ns;
    return 0;
}
