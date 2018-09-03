#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int start=0, end=s.length()-1;
        for(int j=0; j<end;j++){
            int a = (int) s.at(start);
            int b = (int) s.at(start+1);
            int c = (int) s.at(end);
            int d = (int) s.at(end-1);
            start++;
            end--;
            if(abs(a-b) != abs(c-d)){
                cout<<"Not Funny"<<endl;
                goto label;
            }
        }
        cout<<"Funny"<<endl;
        label: continue;
    }
    return 0;
}
