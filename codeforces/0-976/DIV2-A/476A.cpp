#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m; cin>>n>>m;
    if(m > n) cout<<-1<<endl;
    else cout<<(((n+1)/2)+(m-1))/m*m<<endl;
    return 0;
}
