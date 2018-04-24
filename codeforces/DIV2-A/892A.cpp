#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long tmp, sum=0, fmax = -1, smax = -1;
    for (int i = 0; i < n; i++) {
        cin>>tmp;
        sum += tmp;
    }
    for (int j = 0; j < n; ++j) {
        cin>>tmp;
        if(tmp >= fmax){
            smax = fmax;
            fmax = tmp;
        }
        else if(tmp >= smax){
            smax = tmp;
        }
    }
    if (fmax + smax >= sum){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
