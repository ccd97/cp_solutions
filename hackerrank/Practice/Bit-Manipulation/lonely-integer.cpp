#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();){
        int a = v[i];
        int b = 0;
        for(int j=i;v.size();j++){
            if(a == v[j]) b++;
            else{
                i=j;
                break;
            }
        }
        if(b % 2 != 0){
            cout<<a;
            break;
        }
    }
}
