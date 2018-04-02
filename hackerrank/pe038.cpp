#include <bits/stdc++.h>

using namespace std;

unordered_set<char> ds8 = {1, 2, 3, 4, 5, 6, 7, 8};
unordered_set<char> ds9 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check_pd_mul(int no, int k){
    vector<char> digits;
    unordered_set<char> digit_set;
    int mul = 1, mnum;
    while(digits.size() < k){
        mnum = no*mul;
        while(mnum > 0){
            digits.push_back(mnum%10);
            digit_set.insert(mnum%10);
            mnum /= 10;
        }
        mul++;
    }
    if(digits.size() != k)
        return false;
    if(k == 8)
        return digit_set == ds8;
    else
        return digit_set == ds9;
}

int main(int argc, char const *argv[]) {
    int n, k; cin>>n>>k;
    vector<int> pd_mul;
    for(int i=2; i<n; i++){
        if(check_pd_mul(i, k)) pd_mul.push_back(i);
    }
    for(int num : pd_mul){
        cout<<num<<endl;
    }
    return 0;
}
