#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct point{
    long long x;
    long long y;
    long long distance;

    bool operator<(auto& np){
        return distance < np.distance;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    long x1, y1;
    vector<point> bp;
    long ans = 0;
    for(int i=0; i<n; i++){
        cin>>x1>>y1;
        if(x1 == 0 || y1 == 0) ans+=4;
        else ans+=6;
        bp.push_back({x1, y1, abs(x1) + abs(y1)});
    }
    sort(bp.begin(), bp.end());
    cout<<ans<<endl;
    for(int i=0; i<bp.size(); i++){
        if(bp[i].x != 0){
            cout<<1<<" "<<abs(bp[i].x)<<" "<<((bp[i].x > 0)?"R":"L")<<endl;
        }
        if(bp[i].y != 0){
            cout<<1<<" "<<abs(bp[i].y)<<" "<<((bp[i].y > 0)?"U":"D")<<endl;
        }
        cout<<2<<endl;
        if(bp[i].x != 0){
            cout<<1<<" "<<abs(bp[i].x)<<" "<<((bp[i].x > 0)?"L":"R")<<endl;
        }
        if(bp[i].y != 0){
            cout<<1<<" "<<abs(bp[i].y)<<" "<<((bp[i].y > 0)?"D":"U")<<endl;
        }
        cout<<3<<endl;
    }
    return 0;
}
