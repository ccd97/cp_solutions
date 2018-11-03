#include<iostream>
#include<stack>
using namespace std;


int main() {
    string s;
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>s;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s.at(i));
            }
            else if(abs(st.top()-s.at(i))==1 || abs(st.top()-s.at(i))==2){
                st.pop();
            }
            else{
                st.push(s.at(i));
            }
        }
        if(st.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
