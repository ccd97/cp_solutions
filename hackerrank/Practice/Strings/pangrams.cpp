#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int i,j;
    string in;
    bool al,all=true;
    getline(cin,in);
    for(i=0;i<26;i++){
        al = false;
        char s = (char)(i+65);
        char B = (char)(i+97);
        for(j=0;j<in.length();j++){
            if(in.at(j)== s||in.at(j)== B){
                al=true;
                break;
            }
        }
        if(!al){
            all=false;
            break;
        }
    }
    all?cout<<"pangram":cout<<"not pangram";
    return 0;
}
