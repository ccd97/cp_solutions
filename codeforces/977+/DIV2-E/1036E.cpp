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

struct Segment{
    Point p1, p2;

    friend istream &operator >> (istream &in, Segment &seg){
        in>>seg.p1>>seg.p2;
        return in;
    }

    long long calc_int_pnt_on_seg(){
        if (p1.x == p2.x) return abs(p1.y-p2.y) + 1;
        if (p1.y == p2.y) return abs(p1.x-p2.x) + 1;
        return __gcd(abs(p1.x-p2.x), abs(p1.y-p2.y))+1;
    }

    bool point_on_seg(Point& p){
        if (p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x) &&
            p.y <= max(p1.y, p2.y) && p.y >= min(p1.y, p2.y)) return true;
        return false;
    }

    // 0-colinear, 1-clockwise, 2-counterclockwise
    int point_orientation_on_seg(Point &p) {
        long long val = (p2.y-p1.y)*(p.x-p2.x)-(p2.x-p1.x)*(p.y-p2.y);
        if (val == 0) return 0;
        return (val > 0)? 1: 2;
    }

    bool get_int_intersection(Segment& seg, Point& result){
        // a1x + b1y = c1
        long long a1 = p2.y-p1.y;
        long long b1 = p1.x-p2.x;
        long long c1 = a1*p1.x + b1*p1.y;
        // a2x + b2y = c2
        long long a2 = seg.p2.y-seg.p1.y;
        long long b2 = seg.p1.x-seg.p2.x;
        long long c2 = a2*seg.p1.x + b2*seg.p1.y;

        long long determinant = a1*b2 - a2*b1;

        if(determinant == 0) return false;
        if((b2*c1 - b1*c2) % determinant != 0 or
            (a1*c2 - a2*c1) % determinant != 0) return false;

        result.x = (b2*c1 - b1*c2)/determinant;
        result.y = (a1*c2 - a2*c1)/determinant;

        // https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
        int o1 = point_orientation_on_seg(seg.p1);
        int o2 = point_orientation_on_seg(seg.p2);
        int o3 = seg.point_orientation_on_seg(p1);
        int o4 = seg.point_orientation_on_seg(p2);

        if(o1!=o2 and o3!=o4) return true;
        if(o1==0 and point_on_seg(seg.p1)) return true;
        if(o2==0 and point_on_seg(seg.p2)) return true;
        if(o3==0 and seg.point_on_seg(p1)) return true;
        if(o4==0 and seg.point_on_seg(p2)) return true;

        return false;
    }
};



int main(int argc, char const *argv[]) {
    int n; cin>>n;
    Segment seg[n];
    for(int i=0; i<n; i++) cin>>seg[i];

    long long int_pnt_cnt[n];
    memset(int_pnt_cnt, 0, sizeof int_pnt_cnt);

    for(int i=0; i<n; i++)
        int_pnt_cnt[i] = seg[i].calc_int_pnt_on_seg();

    Point p;
    unordered_map<Point, long, Point> intersection_pts;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(seg[i].get_int_intersection(seg[j], p)){
                intersection_pts[p]++;
            }
        }
    }

    long long int_pts = accumulate(int_pnt_cnt, int_pnt_cnt+n , 0ll);

    for(auto pr : intersection_pts){
        long common_pts = (1+(int)sqrt(1+8*pr.second))/2-1;
        int_pts -= common_pts;
    }

    cout<<int_pts<<endl;

    return 0;
}
