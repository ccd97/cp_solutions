#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int count =0;
        int ptr1=0,ptr2=0;
        while(ptr1<s.length() && ptr2<s.length()){
            while(s.at(ptr1)==s.at(ptr2)){
                ptr2++;
                if(ptr2 >= s.length()){
                    break;
                }
            }
            ptr2--;
            count += (ptr2-ptr1);
            ptr1 = ptr2;
            ptr1++;
            ptr2 = ptr1;
        }
        cout<<count<<endl;
    }
    return 0;
}
