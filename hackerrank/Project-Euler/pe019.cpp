#include <bits/stdc++.h>

using namespace std;
struct Date {
    unsigned long long y;
    unsigned int m, d;

    bool operator <=(const Date& dt) {
        if(y == dt.y)
            if(m == dt.m)
                return d <= dt.d;
            else return m <= dt.m;
        else return y <= dt.y;
    }

    void next1stDay(){
        d = 1;
        if(m == 12){
            y++; m=1;
        }
        else m++;
    }
};

int dayofweek(Date d) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    d.y -= d.m < 3;
    return ( d.y + d.y/4 - d.y/100 + d.y/400 + t[d.m-1] + d.d) % 7;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        Date d1, d2;
        cin>>d1.y>>d1.m>>d1.d;
        cin>>d2.y>>d2.m>>d2.d;
        int ans = 0;
        if(d1.d != 1) d1.next1stDay();
        while(d1 <= d2){
            if(dayofweek(d1) == 0) ans++;
            d1.next1stDay();
        }
        cout<<ans<<endl;
    }
    return 0;
}
