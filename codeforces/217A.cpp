#include <bits/stdc++.h>

using namespace std;

bool gph[1005][1005];
bool visisted[1005][1005];

void dfs(int x, int y){
    if(visisted[x][y] == 0) visisted[x][y] = 1;
    else return;
    for(int i=0; i<1005; i++){
        if(gph[x][i] == 1) dfs(x, i);
    }
    for(int i=0; i<1005; i++){
        if(gph[i][y] == 1) dfs(i, y);
    }
}

int main(int argc, char const *argv[]) {
    int n, t1 ,t2; cin>>n;
    for(int i=0; i<1005; i++){
        for(int j=0; j<1005; j++){
            gph[i][j] = 0;
            visisted[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        cin>>t1>>t2;
        gph[t1][t2] = 1;
    }
    int islands = 0;
    while(true){
        int x=-1, y=-1;
        for(int i=0; i<1005; i++){
            bool found = false;
            for(int j=0; j<1005; j++){
                if(visisted[i][j] == 0 && gph[i][j] == 1){
                    x = i, y = j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(x==-1 || y==-1) break;
        dfs(x, y);
        islands++;
    }
    cout<<islands-1<<endl;
    return 0;
}
