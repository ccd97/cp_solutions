#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x, int base) {
    if (x < 0) return false;
    int div = 1;
    while (x / div >= base) {
        div *= base;
    }
    while (x != 0) {
        int l = x / div;
        int r = x % base;
        if (l != r) return false;
        x = (x % div) / base;
        div /= base*base;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int n, k; cin>>n>>k;
    vector<int> palind;
    vector<int> dbpalind;
    for(int i=1; i<n; i++){
        if(isPalindrome(i, 10)) palind.push_back(i);
    }
    for(auto pn: palind){
        if(isPalindrome(pn, k)) dbpalind.push_back(pn);
    }
    unsigned long long sumdbp = 0;
    for(auto dppn: dbpalind) sumdbp += dppn;
    cout<<sumdbp<<endl;
    return 0;
}
