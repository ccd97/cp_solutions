#include <iostream>

using namespace std;

int gph[100][100] = {0};
int tn[100] = {0};

void calculatetn(int n, int parent){
    int nodes = 1;
    for(int i=0; i<n; i++){
        if(gph[i][parent]){
            calculatetn(n, i);
            nodes += tn[i];
        }
    }
    tn[parent] = nodes;
}

int main(int argc, char const *argv[]) {
    int n,m,t1,t2;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>t1>>t2;
        if(t1 < t2){
            t1 ^= t2; t2 ^= t1; t1 ^= t2;
        }
        gph[t1-1][t2-1] = 1;
    }
    int parent = 0;
    for(int i=0; i<n; i++){
        bool success = true;
        for(int j=0; j<n; j++){
            if(gph[i][j] != 0) { success = false; break; }
        }
        if(success) { parent = i; break; }
    }
    int res = 0;
    calculatetn(n, parent);
    for(int i=0; i<n; i++){
        if(tn[i] % 2 == 0) res++;
    }
    cout<<res-1<<endl;
}
