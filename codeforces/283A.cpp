#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, t1, t2, alen=1; cin>>n;
    int arr[n]; arr[0] = 0;
    long inc[n];
    memset(inc, 0, sizeof(inc));
    long long asum = 0;
    while(n--){
        int qt; cin>>qt;
        if(qt == 1){
            cin>>t1>>t2;
            inc[t1-1] += t2;
            asum += t1*t2;
        }
        else if(qt == 2){
            cin>>t1;
            asum += t1;
            arr[alen] = t1;
            alen++;
        }
        else if(qt == 3){
            asum -= arr[alen-1] + inc[alen-1];
            inc[alen-2] += inc[alen-1];
            inc[alen-1] = 0;
            alen--;
        }
        cout<<setprecision(10)<<1.0*asum/alen<<endl;
    }
}
