#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    friend istream &operator >> (istream &in, Point &p){
        in>>p.x>>p.y;
        return in;
    }

    size_t operator()(const Point& p) const {
        return ((p.x + p.y)*(p.x + p.y + 1)/2) + p.y; // hash
    }

    bool operator==(const Point& p) const {
        return p.x==x and p.y==y;
    }

};

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    Point p;
    unordered_map<Point, int, Point> points;
    unordered_map<long long, int> same_x_mp, same_y_mp;
    for(int i=0; i<n; i++){
        cin>>p;
        points[p]++;
    }
    long long ans = 0;
    for(auto pnt : points){
        ans -= (1ll*pnt.second*(pnt.second-1))/2;
        same_x_mp[pnt.first.x] += pnt.second;
        same_y_mp[pnt.first.y] += pnt.second;
    }
    for(auto xcor : same_x_mp){
        ans += (1ll*xcor.second*(xcor.second-1))/2;
    }
    for(auto ycor: same_y_mp){
        ans += (1ll*ycor.second*(ycor.second-1))/2;
    }
    cout<<ans<<endl;
    return 0;
}
