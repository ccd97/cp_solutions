#include <bits/stdc++.h>

using namespace std;

double b_numsearch(double num){
    double lo = 0.0, hi = 2.0;
    while(hi-lo >= 1e-9){
        double mid = (lo + hi)/2.0;
        double mul = mid * (num - mid);
        if(mul < num) lo = mid;
        else hi = mid;
    }
    return (lo+hi)/2;
}

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        double num, b; cin>>num;
        if(num == 0) b = 0.0;
        else if(num < 4) {
            cout<<"N"<<endl;
            continue;
        }
        else b = b_numsearch(num);

        cout<<setprecision(10)<<"Y "<<num-b<<" "<<b<<endl;
    }
    return 0;
}
