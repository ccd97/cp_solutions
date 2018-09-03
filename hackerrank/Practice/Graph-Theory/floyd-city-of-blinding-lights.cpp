#include <iostream>
#include <algorithm>

#define INT_MAX 150000

using namespace std;

int main() {
    int N,M,Q,n1,n2,w;
    cin>>N>>M;

    int graph[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INT_MAX;

    for(int i=0;i<M;i++){
        cin>>n1>>n2>>w;n1--,n2--;
        graph[n1][n2] = w;
    }

    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    cin>>Q;

    for(int i=0;i<Q;i++){
        cin>>n1>>n2;n1--,n2--;
        cout<<((graph[n1][n2] == INT_MAX) ? -1 : graph[n1][n2])<<endl;
    }
}
