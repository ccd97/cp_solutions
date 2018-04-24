#include <bits/stdc++.h>

using namespace std;

struct pld{
    int o;
    int d;
};

int main(int argc, char const *argv[]) {
    int n, p; cin>>n>>p;
    p--;
    string s; cin>>s;
    vector<pld> vp;
    for(unsigned int i=0; i<s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]){
            if(p < s.size()/2){
                vp.push_back({i, min(abs(s[i]-s[s.size()-1-i]), 26 - abs(s[i]-s[s.size()-i-1]))});
            }
            else{
                vp.push_back({s.size()-1-i, min(abs(s[i]-s[s.size()-1-i]), 26 - abs(s[i]-s[s.size()-i-1]))});
            }
        }
    }
    long long sum = 0;
    if (vp.size() == 0){
        cout<<0<<endl;
    }
    else if(vp.size() == 1){
        cout<<abs(vp[0].o - p) + vp[0].d<<endl;
    }
    else{
        for(pld p: vp){
            sum += p.d;
        }
        int path1 = abs(p - vp[0].o) + min(abs(vp[0].o - vp[vp.size()-1].o), (int)s.size()/2 + abs(vp[0].o - vp[vp.size()-1].o));
        int path2 = abs(p - vp[vp.size()-1].o) + min(abs(vp[vp.size()-1].o - vp[0].o), (int)s.size()/2 + abs(vp[0].o - vp[vp.size()-1].o));
        cout<<sum+min(path1, path2)<<endl;
    }

    return 0;
}
