#include<bits/stdc++.h>

using namespace std;

bool arr_o[2003][2003];
int dist[2003][2003];
pair<int, int> lrm[2003][2003];

struct node{
    int x, y, xm, ym;
};

void bfs(int n, int m, int r, int c, long x, long y){
    deque<node> dq;
    dist[r][c] = 0;
    dq.emplace_back(node{r, c, 0, 0});

    while(!dq.empty()){
        auto v = dq.front();
        dq.pop_front();

        if(v.y-1 >= 0 and !arr_o[v.x][v.y-1]){
            if(dist[v.x][v.y-1] > dist[v.x][v.y] + 1){
                dist[v.x][v.y-1] = dist[v.x][v.y] + 1;
                lrm[v.x][v.y-1] = {v.xm+1, v.ym};
                dq.emplace_back(node{v.x, v.y-1, v.xm+1, v.ym});
            }
        }

        if(v.y+1 < m and !arr_o[v.x][v.y+1]){
            if(dist[v.x][v.y+1] > dist[v.x][v.y] + 1){
                dist[v.x][v.y+1] = dist[v.x][v.y] + 1;
                lrm[v.x][v.y+1] = {v.xm, v.ym+1};
                dq.emplace_back(node{v.x, v.y+1, v.xm, v.ym+1});
            }
        }


        if(v.x-1 >= 0 and !arr_o[v.x-1][v.y]){
            if(dist[v.x-1][v.y] > dist[v.x][v.y]){
                dist[v.x-1][v.y] = dist[v.x][v.y];
                lrm[v.x-1][v.y] = {v.xm, v.ym};
                dq.emplace_front(node{v.x-1, v.y, v.xm, v.ym});
            }
        }


        if(v.x+1 < n and !arr_o[v.x+1][v.y]){
            if(dist[v.x+1][v.y] > dist[v.x][v.y]){
                dist[v.x+1][v.y] = dist[v.x][v.y];
                lrm[v.x+1][v.y] = {v.xm, v.ym};
                dq.emplace_front(node{v.x+1, v.y, v.xm, v.ym});
            }
        }
    }

}

int main(int argc, char const *argv[]) {
    int n, m, r, c; long x, y; string tmp;
    cin>>n>>m>>r>>c>>x>>y;
    for(int i=0; i<n; i++){
        cin>>tmp;
        for(int j=0; j<m; j++){
            dist[i][j] = INT_MAX;
            if(tmp[j] == '*')
                arr_o[i][j] = true;
            else
                arr_o[i][j] = false;
        }
    }
    bfs(n, m, r-1, c-1, x, y);
    long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] <= x+y and lrm[i][j].first <= x and lrm[i][j].second <= y) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
