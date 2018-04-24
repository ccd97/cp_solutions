#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        long tmp;
        unordered_set<long> st;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>tmp;
            st.insert(tmp);
        }
        cout<<n-st.size()<<endl;
    }
    return 0;
}
