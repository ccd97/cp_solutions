#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])  {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int mxc = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int lhs = (n - a*i - b*j);
            if(lhs >= 0 && lhs % c == 0){
                mxc = max(mxc, i + j + lhs/c);
            }
        }
    }
    cout<<mxc<<endl;
    return 0;
}
