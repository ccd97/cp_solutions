#include <bits/stdc++.h>

using namespace std;

auto lcs(string X, string Y) {
    int m = X.size(), n = Y.size();
    int L[m+1][n+1];
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i-1] == Y[j-1]) L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        string a, b; cin>>a>>b;

        string X = "";
        string Y = "";
        for(int i=0; i<a.size(); i++){
            if(a[i] != X.back()) X += a[i];
        }
        for(int i=0; i<b.size(); i++){
            if(b[i] != Y.back()) Y += b[i];
        }

        auto lcslen = lcs(X, Y);

        cout<<X.size() + Y.size() - lcslen<<endl;
    }
    return 0;
}

// 1 9 9 vhovvpfqy mvbsbfnaq
// ans - 14
