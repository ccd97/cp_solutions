#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int x = 0;
    string inp;
    for(int i=0; i<n; i++){
        cin>>inp;
        if(inp == "X++" || inp == "++X") x++;
        else if(inp == "X--" || inp == "--X") x--;
    }
    cout<<x<<endl;
    return 0;
}
