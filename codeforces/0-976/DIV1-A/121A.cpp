#include <bits/stdc++.h>

using namespace std;

vector<long long> vec;

void gen_lnums(long long curr, int no_digit){
    if(!no_digit)
        vec.push_back(curr);
    else{
        gen_lnums(curr*10+4, no_digit-1);
        gen_lnums(curr*10+7, no_digit-1);
    }
}

int main(int argc, char const *argv[]) {
    for(int i=1;  i<=10; i++)
        gen_lnums(0, i);
    sort(vec.begin(), vec.end());
    long long l, r; cin>>l>>r;
    auto itl = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
    auto itr = lower_bound(vec.begin(), vec.end(), r) - vec.begin();
    if(itl == itr){
        cout<<(r-l+1)*vec[itl]<<endl;
        return 0;
    }
    unsigned long long ans = 0;
    for(int i = itl; i<itr-1; i++){
        ans += vec[i+1]*(vec[i+1]-vec[i]);
    }
    ans += vec[itl] * (vec[itl]-l+1);
    ans += vec[itr] * (r - vec[itr-1]);
    cout<<ans<<endl;
    return 0;
}
