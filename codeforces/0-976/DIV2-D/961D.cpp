#include <bits/stdc++.h>

using namespace std;

long double inf = std::numeric_limits<long double>::infinity();

struct Point {
    long x, y;

    friend istream &operator >> (istream &in, Point &p){
        in>>p.x>>p.y;
        return in;
    }
};

bool is_colinear(Point& a, Point& b, Point &c){
    return (1ll*(c.y-b.y)*(b.x-a.x) == 1ll*(b.y-a.y)*(c.x-b.x));
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    Point points[n];
    Point spoints[n][3];
    long double slope[n][3];
    for(int i=0; i<n; i++) cin>>points[i];

    if(n <= 4){
        cout<<"YES"<<endl; return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            spoints[i][j].x = points[i].x - points[j].x;
            spoints[i][j].y = points[i].y - points[j].y;
        }
    }
    for(int j=0; j<3; j++){
        for(int i=0; i<n; i++){
            if(i==j) continue;
            if(spoints[i][j].y == 0) slope[i][j] = inf;
            else slope[i][j] = spoints[i][j].x/((long double)spoints[i][j].y);
        }
    }
    unordered_map<long double, int> slope_c[3];
    for(int j=0; j<3; j++){
        for(int i=0; i<n; i++){
            if(i==j) continue;
            slope_c[j][slope[i][j]]++;
        }
    }
    int maxc[3] = {0,0,0};
    int nonc[3] = {0,0,0};
    long double slp_of_mx[3];
    for(int j=0; j<3; j++){
        for(auto p: slope_c[j]){
            if(p.second != 1) nonc[j]++;
            if(p.second > maxc[j])
                maxc[j] = p.second, slp_of_mx[j] = p.first;
        }
    }

    int maxpos = max_element(maxc, maxc+3) - maxc;

    vector<int> pts_to_check;
    for(int i=0; i<n; i++){
        if(i != maxpos and slp_of_mx[maxpos] != slope[i][maxpos])
            pts_to_check.push_back(i);
    }

    bool colin = true;
    int pts_vec_sz = pts_to_check.size();
    for(int i=0; i+2<pts_vec_sz and colin; i++){
        colin = is_colinear(points[pts_to_check[i]],
                            points[pts_to_check[i+1]],
                            points[pts_to_check[i+2]]);
    }

    if(colin)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
