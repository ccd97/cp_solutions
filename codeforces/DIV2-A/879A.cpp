#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, t1, t2; cin>>n;
    long long result = 0;
    float tn;
    for(int i=0; i<n; i++){
        cin>>t1>>t2;
        if(t1 > result) result = t1;
        else if(t1 == result) result = t1 + t2;
        else{
            result = t1 + ceil(1.0*(result+1-t1)/t2)*t2;
        }
    }
    cout<<result<<endl;
    return 0;
}
