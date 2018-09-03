#include <iostream>
using namespace std;

int toInt(char ch){
    return ch - '0';
}

int main(){
    int n,i,j,max=0;
    cin >> n;
    string s[n];
    cin.ignore();
    for(i = 0;i < n;i++){
        getline(cin,s[i]);
    }
    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
            int a = toInt(s[i].at(j));
            int a1 = toInt(s[i].at(j+1));
            int a2 = toInt(s[i].at(j-1));
            int a3 = toInt(s[i+1].at(j));
            int a4 = toInt(s[i-1].at(j));
            if(a>a1 && a>a2 && a>a3 && a>a4) s[i].at(j) = 'X';
        }
    }
    for(i = 0;i < n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
