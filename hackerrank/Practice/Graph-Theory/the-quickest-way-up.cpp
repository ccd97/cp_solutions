#include <iostream>

#define INT_MAX 99999
using namespace std;

int gph[101][101];

int minDistance(int dist[], bool sptSet[]) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < 101; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
   return min_index;
}

int dijkstra(int src) {
     int dist[101];
     bool sptSet[101];
     for (int i = 0; i < 101; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < 100; count++) {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < 101; v++)
         if (!sptSet[v] && dist[u] != INT_MAX && dist[u]+gph[u][v] < dist[v])
            dist[v] = dist[u] + gph[u][v];
     }
     return dist[100];
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++)
                gph[i][j] = INT_MAX;
        for(int i=1; i<=99; i++){
            for(int j=1; j<=6; j++) {
                if(i+j <= 100) gph[i][i+j] = 1;
            }
        }
        int t1, t2;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>t1>>t2;
            for(int j=1; j<=6; j++){
                if(t1-j >= 1){
                    gph[t1-j][t2] = 1;
                    gph[t1-j][t1] = INT_MAX;
                }
            }
        }
        int m; cin>>m;
        for(int i=0; i<m; i++){
            cin>>t1>>t2;
            for(int j=1; j<=6; j++){
                if(t1-j >= 1){
                    gph[t1-j][t2] = 1;
                    gph[t1-j][t1] = INT_MAX;
                }
            }
        }
        int ans = dijkstra(1);
        if(ans == INT_MAX) ans = -1;
        cout<<ans<<endl;
    }
}
