#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n], lo[n] = {0}, hi[n] = {0};
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=1; i<n; i++){
            lo[i] = max(lo[i-1]+0, hi[i-1]+abs(a[i-1]- 1));
            hi[i] = max(lo[i-1]+abs(a[i] - 1), hi[i-1]+abs(a[i]-a[i-1]));
        }
        cout<<max(lo[n-1], hi[n-1])<<endl;
    }
}
