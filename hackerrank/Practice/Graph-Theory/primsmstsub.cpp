#include <iostream>
#include <climits>

#define getGraph(n,e,gph,wth,start)  \
    int n,e,start; std::cin>>e>>n;  \
    int gph[e][e],wth[e];           \
    for(int i=0; i<e; i++)          \
    for(int j=0; j<e; j++)          \
    gph[i][j] = INFINITY;           \
    int n1,n2,w;                    \
    for(int i=0; i<n; i++){         \
        std::cin>>n1>>n2>>w;        \
        n1--, n2--;                 \
        if(w<gph[n1][n2])           \
            gph[n1][n2] = w;        \
        if(w<gph[n2][n1])           \
            gph[n2][n1] = w;        \
    }                               \
    std::cin>>start;                \
    start--

#define ans(x) std::cout<<x<<std::endl
#define debug(tag,x) std::cout<<tag<<" : "<<x<<std::endl

#define INFINITY INT_MAX

int main() {
    getGraph(n,e,gph,wth,start);
    bool vgph[e][e],vrow[e];
    for(int i=0; i<e; i++) {
        vrow[i] = false;
        vgph[i][i] = true;
        for(int j = 0; j<e ;j++){
            if(gph[i][j] == INFINITY) vgph[i][j] = true;
            else vgph[i][j] = false;
        }
    }
    vrow[start] = true;
    int sum = 0;
    for (int z=1; z<e; z++){
        int sml=INFINITY,idx_i=-1,idx_j=-1;
        for(int i=0; i<e; i++) {
            if(!vrow[i]) continue;
            for(int j=0; j<e; j++) {
                if(vgph[i][j]) continue;
                if(gph[i][j]<=sml && !vrow[j]) {
                    sml = gph[i][j];
                    idx_i = i;
                    idx_j = j;
                }
            }
        }
        //debug("sum",sum);
        vgph[idx_i][idx_j] = true;
        vgph[idx_j][idx_i] = true;
        vrow[idx_j] = true;
        sum += sml;

    }
    ans(sum);
}
