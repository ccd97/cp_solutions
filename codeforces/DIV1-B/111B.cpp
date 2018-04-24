#include <bits/stdc++.h>

using namespace std;

vector<int> divs[100005];
int ld[100005];

int main(int argc, char const *argv[]) {
    for(int i=1; i<100005; i++){
        for(int j=1; j<100005; j+=i){
            divs[j].push_back(i);
        }
    }
    int n, t1, t2; cin>>n;
    for(int i=1; i<n+1; i++){
        int ans = 0;
        cin>>t1>>t2; t1++;
        for(int d: divs[t1]){
            if(ld[d] < i-t2 || t2==0){
                ans++;
            }
            ld[d] = i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
