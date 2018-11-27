#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x, y;

    friend istream &operator >> (istream &in, Point &p){
        in>>p.x>>p.y;
        return in;
    }

};

struct Line {
    long double a, b, c;

    Line(long double a=0, long double b=0, long double c=0):
        a(a), b(b), c(c) {}

    Line(Point& p1, Point& p2){
        a = p1.y-p2.y;
        b = p2.x-p1.x;
        c = p1.x*p2.y-p2.x*p1.y;
    }

    friend istream &operator >> (istream &in, Line &l){
        in>>l.a>>l.b>>l.c;
        return in;
    }

    long double get_slope(){
        return -1*a/b;
    }
};

struct Segment{
    Point p1, p2;

    friend istream &operator >> (istream &in, Segment &seg){
        in>>seg.p1>>seg.p2;
        return in;
    }

    bool point_on_seg(Point& p){
        if (p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x) &&
            p.y <= max(p1.y, p2.y) && p.y >= min(p1.y, p2.y)) return true;
        return false;
    }

    bool does_intersect(Line& line){
        Point inter;
        Line cline = Line(p1, p2);
        long double den = (line.a*cline.b)-(line.b*cline.a);
        if(den == 0)
            return false;
        inter.x = ((cline.c*line.b)-(cline.b*line.c))/den;
        inter.y = ((cline.a*line.c)-(cline.c*line.a))/den;
        if(point_on_seg(inter))
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[]) {
    Point a, b; cin>>a>>b;
    Segment ab = {a, b};
    int n; cin>>n;
    Line lines[n];
    for(int i=0; i<n; i++)
        cin>>lines[i];
    long ans = 0;
    for(int i=0; i<n; i++)
        if(ab.does_intersect(lines[i])) ans++;
    cout<<ans<<endl;
    return 0;
}
