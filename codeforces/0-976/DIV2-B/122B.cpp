#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    int c4=0, c7=0;
    for(auto ch : s)
        if(ch == '4') c4++;
        else if(ch == '7') c7++;
    if(c4 == 0 and c7 == 0)
        cout<<-1<<endl;
    else
        cout<<(c7>c4?7:4)<<endl;
    return 0;
}
