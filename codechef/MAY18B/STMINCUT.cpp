#include <bits/stdc++.h>

using namespace std;

bool vuse[1003];
vector<pair<int, long>> ghtree[1003];
long res[1003][1003];
multimap<long, pair<int,int>, greater<long>> gimap;
pair<int,int> subsets[1003];

void dfsl(int start, int dstart, long mn){
    vuse[dstart] = true;
    if(mn != LONG_MAX) {
        if(!res[start][dstart]) res[start][dstart] = mn;
        else min(res[start][dstart], mn);
        if(!res[dstart][start]) res[dstart][start] = mn;
        else min(res[start][dstart], mn);
    }
    for(auto v : ghtree[dstart]){
        if(!vuse[v.first]){
            dfsl(start, v.first, min(mn, v.second));
        }
    }
}

int kghfind(int i){
    if(subsets[i].first != i)
        subsets[i].first = kghfind(subsets[i].first);
    return subsets[i].first;
}

void kghunion(int x, int y){
    int xroot = kghfind(x);
    int yroot = kghfind(y);
    if(subsets[xroot].second < subsets[yroot].second)
        subsets[xroot].first = yroot;
    else if (subsets[xroot].second > subsets[yroot].second)
        subsets[yroot].first = xroot;
    else {
        subsets[yroot].first = xroot;
        subsets[xroot].second++;
    }
}

void construct_ghtree(int n){
    int no_edges = 0;

    for(int i=0; i<n; i++) subsets[i] = {i, 0};

    for(auto v : gimap){
        auto vtx = v.second;
        int x = kghfind(vtx.first);
        int y = kghfind(vtx.second);
        if(x != y){
            no_edges++;
            ghtree[vtx.first].emplace_back(vtx.second, v.first);
            ghtree[vtx.second].emplace_back(vtx.first, v.first);
            kghunion(x, y);
        }
        if(no_edges >= n-1) break;
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        gimap.clear();
        int n; cin>>n;

        long ginit[n][n];
        memset(vuse, false, sizeof(vuse));
        for(int i=0; i<n; i++) ghtree[i].clear();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>ginit[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(ginit[i][j] != 0)
                    gimap.emplace(ginit[i][j], make_pair(i,j));
            }
        }

        construct_ghtree(n);

        memset(res, 0, sizeof(res));
        for(int i=0; i<n; i++){
            memset(vuse, false, sizeof(vuse));
            dfsl(i, i, LONG_MAX);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans += res[i][j] - ginit[i][j];
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
