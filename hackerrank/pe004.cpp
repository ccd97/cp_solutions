#include <bits/stdc++.h>

using namespace std;

bool checkPal(int num){
    int n = num;
    int dig, rev = 0;
    while (num > 0) {
        dig = num % 10;
        rev = rev * 10 + dig;
        num  /= 10;
    }
    return (n == rev);
}

int main(int argc, char const *argv[]) {
    unordered_set<int> pro;
    vector<int> pal;
    for(int i=100; i<1000; i++){
        for(int j=i+1; j<1000; j++){
            pro.insert(i*j);
        }
    }
    for(int i=101101; i<1000000; i++){
        if(checkPal(i)) pal.push_back(i);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int idx = lower_bound(pal.begin(), pal.end(), n) - pal.begin() - 1;
        for(int i=idx; i>=0; i--){
            if(pro.find(pal[i]) != pro.end()){
                cout<<pal[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
