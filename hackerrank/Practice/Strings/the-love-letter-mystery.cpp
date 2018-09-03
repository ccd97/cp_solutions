#include <iostream>
using namespace std;

int main() {
    int t,l,c;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        l = s.length();
        c=0;
        for(int j=0;j<l/2;j++){
            char a = s.at(j);
            char b = s.at(l-j-1);
            while(a!=b){
                if(a>b) a--;
                else if(b>a) b--;
                c++;
            }
        }
        cout<<c<<endl;

    }
    return 0;
}
