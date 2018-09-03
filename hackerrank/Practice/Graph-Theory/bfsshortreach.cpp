#include <iostream>
#include <climits>

using namespace std;

#define INFINITY INT_MAX

int main(){
    int test_cases;
    cin>>test_cases;
    while (test_cases--){
        int nodes, edges, start;
        cin>>edges>>nodes;

        int gph[edges][edges];
        int wth[edges];
        bool vis[edges];

        for (int i = 0; i < edges; i++)
            for (int j = 0; j < edges; j++)
                gph[i][j] = -1;

        int node1, node2, weight = 6;
        for (int i = 0; i < nodes; i++) {
            cin>>node1>>node2;
            node1--,node2--;
            gph[node1][node2] = weight;
            gph[node2][node1] = weight;
        }

        for (int i = 0; i < edges; i++) {
            wth[i] = INFINITY;
            vis[i] = false;
        }

        cin>>start;
        start--;
        wth[start] = 0;

        for (int i = 0; i < edges; i++) {

            int sidx = -1, shd = INFINITY, tmp_sum;
            for (int j = 0; j < edges; j++) {
                if (vis[j]) continue;
                if (wth[j] <= shd) {
                    shd = wth[j];
                    sidx = j;
                }
            }

            for (int j = 0; j < edges; j++) {
                if (j == sidx || vis[j]) continue;
                if (gph[sidx][j] == -1) continue;
                tmp_sum = wth[sidx] + gph[sidx][j];
                if (tmp_sum < wth[j]) wth[j] = tmp_sum;
            }

            vis[sidx] = true;
        }

        for (int i = 0; i < edges; i++) {
            if (i == start) continue;
            if (wth[i] == INFINITY || wth[i] < 0) cout<<"-1"<<" ";
            else cout<<wth[i]<<" ";
        }

        cout<<endl;
    }
}
