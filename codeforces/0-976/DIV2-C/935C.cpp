#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x, y;

    Point(long double x=0, long double y=0): x(x), y(y) {}

    friend istream &operator >> (istream &in, Point &p){
        in>>p.x>>p.y;
        return in;
    }

    bool operator==(const Point& p) const {
        return p.x==x and p.y==y;
    }

    long double get_distance(Point& p){
        return sqrt(pow(p.x-x, 2) + pow(p.y-y, 2));
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

    long double get_intercept(){
        return -1*c/b;
    }
};

struct Circle {
    Point c;
    long double r;

    Circle(Point& c, long double r): c(c), r(r) {}

    bool point_in_circle(Point& p){
        return sqrt(pow(p.x-c.x, 2) + pow(p.y-c.y, 2)) <r;
    }

    vector<Point> get_intersection(Line& l){
        vector<Point> inter_pts;

        long double m = l.get_slope();
        long double d = l.get_intercept();

        long double den = 1+m*m;
        long double del = r*r*den - pow(c.y-m*c.x-d, 2);

        if(isinf(m)) del = r*r - pow(-l.c/l.a-c.x, 2);

        if(del<0) //doesnt intersect
            return inter_pts;

        Point p1, p2;

        if(isinf(m)){
            p1.x = -l.c/l.a;
            p1.y = c.y-(sqrt(pow(l.a*r, 2)-pow(l.a*c.x, 2)-2*c.x*l.a*l.c-l.c*l.c))/l.a;

            p2.x = -l.c/l.a;
            p2.y = c.y+(sqrt(pow(l.a*r, 2)-pow(l.a*c.x, 2)-2*c.x*l.a*l.c-l.c*l.c))/l.a;
        }
        else{
            p1.x = (c.x+c.y*m-d*m+sqrt(del))/den;
            p1.y = (d+c.x*m+c.y*m*m+m*sqrt(del))/den;

            p2.x = (c.x+c.y*m-d*m-sqrt(del))/den;
            p2.y = (d+c.x*m+c.y*m*m-m*sqrt(del))/den;
        }

        if(del == 0) // tangent
            inter_pts.push_back(p1);
        else{
            inter_pts.push_back(p1);
            inter_pts.push_back(p2);
        }

        return inter_pts;
    }
};

Point get_midpoint(Point& p1, Point& p2){
    return Point((p1.x+p2.x)/(double)2, (p1.y+p2.y)/(double)2);
}

int main(int argc, char const *argv[]) {
    long double R, r; Point p1, p2, pap;
    cin>>R>>p1>>p2;
    Circle mainc(p1, R);
    if(!mainc.point_in_circle(p2)){
        cout<<setprecision(20)<<p1.x<<" "<<p1.y<<" "<<R<<endl;
        return 0;
    }
    if(p1 == p2){
        cout<<setprecision(20)<<p1.x+R/2<<" "<<p1.y<<" "<<R/2<<endl;
        return 0;
    }
    Line cntr_fafa(p1, p2);
    auto intersp = mainc.get_intersection(cntr_fafa);

    auto d1 = intersp[0].get_distance(p2);
    auto d2 = intersp[1].get_distance(p2);

    if(d1 > d2){
        pap = get_midpoint(p2, intersp[0]);
        r = d1/2;
    }
    else{
        pap = get_midpoint(p2, intersp[1]);
        r = d2/2;
    }

    cout<<setprecision(20)<<pap.x<<" "<<pap.y<<" "<<r<<endl;

    return 0;
}
