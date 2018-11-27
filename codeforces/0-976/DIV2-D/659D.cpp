#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    friend istream &operator >> (istream &in, Point &p){
        in>>p.x>>p.y;
        return in;
    }

};

long double calc_area_triangle(Point& a, Point& b, Point& c) {
    return 0.5 * (a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y));
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    Point points[n+1];
    for(int i=0; i<n+1; i++)
        cin>>points[i];

    int ans = 0;

    for(int i=1; i<n; i++){
        // if area is negative then convex
        if(calc_area_triangle(points[i-1], points[i], points[i+1]) < 0)
            ans++;
    }

    cout<<ans<<endl;

    return 0;
}
