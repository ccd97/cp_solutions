#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int days(int y,int m,int d){
    m = (m + 9) % 12;
    y = y - m/10;
    return (365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 ));
}

int main() {
    int d1,m1,y1,d2,m2,y2,fine;
    cin>>d1>>m1>>y1;
    cin>>d2>>m2>>y2;
    if (days(y1,m1,d1)-days(y2,m2,d2)<0 ) fine = 0;
    else if (y1-y2!=0) fine = 10000;
    else if (m1-m2!=0) fine = 500*(m1-m2);
    else if (d1-d2!=0) fine = 15*(d1-d2);
    if(fine < 0 ) fine = 0;
    cout<<fine;
    return 0;
}
