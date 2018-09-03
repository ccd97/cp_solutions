#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1,s2;
    int a[26],b[26],count=0;
    for(int i=0 ;i<26;i++){
        a[i]=0;
        b[i]=0;
    }
    cin>>s1>>s2;
    for(int i = 0;i<s1.length();i++){
        a[s1.at(i)-97]++;
    }
    for(int i = 0;i<s2.length();i++){
        b[s2.at(i)-97]++;
    }
    for(int i=0;i<26;i++){
        count += abs(a[i]-b[i]);
    }
    cout<<count;
    return 0;
}
