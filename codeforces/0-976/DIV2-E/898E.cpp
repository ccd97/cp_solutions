#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long x) {
    long double sr = sqrt(x);
    return ((sr-floor(sr)) == 0);
}

long nearest_square_diff(long n) {
    long double root = sqrt(n);
    long fr = floor(root);
    long cr = ceil(root);
    return min(abs(fr*fr - n), abs(cr*cr - n));
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    vector<long> sqrs, nsqrs;
    long num;
    for(int i=0; i<n; i++){
        cin>>num;
        if(isPerfectSquare(num))
            sqrs.push_back(num==0?2:1);
        else
            nsqrs.push_back(nearest_square_diff(num));
    }

    sort(sqrs.begin(), sqrs.end());
    sort(nsqrs.begin(), nsqrs.end());

    long long ans = 0;

    int diff = ((int)sqrs.size()-(int)nsqrs.size())/2;
    if(diff > 0)
        for(int i=0; i<diff; i++) ans += sqrs[i];
    else if(diff < 0)
        for(int i=0; i<-diff; i++) ans += nsqrs[i];

    cout<<ans<<endl;

    return 0;
}
