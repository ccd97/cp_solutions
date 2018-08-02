#include <bits/stdc++.h>

using namespace std;

bool check(int hr, int mi){
    if(hr%10 == 7 || mi % 10 == 7) return true;
    else return false;
}

int main(int argc, char const *argv[]) {
    int st; cin>>st;
    int hr, mi; cin>>hr>>mi;
    int ans = 0;
    while(!check(hr, mi)){
        ans++;
        mi -= st;
        if(mi < 0){
            mi += 60;
            hr--;
        }
        if(hr < 0){
            hr += 24;
        }
    }
    cout<<ans<<endl;
    return 0;
}
