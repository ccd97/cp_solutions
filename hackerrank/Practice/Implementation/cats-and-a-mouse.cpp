#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int q; cin>>q;
    int a, b, c;
    while(q--){
        cin>>a>>b>>c;
        if(abs(c-a) < abs(c-b)) cout<<"Cat A"<<endl;
        else if(abs(c-a) > abs(c-b)) cout<<"Cat B"<<endl;
        else cout<<"Mouse C"<<endl;
    }
    return 0;
}
