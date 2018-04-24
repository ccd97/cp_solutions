#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s1, s2; cin>>s1>>s2;
    int n = s1.size();
    int p1 = 0;
    vector<int> p2 = {0};
    for(int i=0; i<n; i++){
        if(s1[i] == '+' && s2[i] == '+'){
            p1++;
            for(int  j=0; j<p2.size(); j++) p2[j]++;
        }
        else if(s1[i] == '-' && s2[i] == '-'){
            p1--;
            for(int  j=0; j<p2.size(); j++) p2[j]--;
        }
        else if(s1[i] == '+' && s2[i] == '-'){
            p1++;
            for(int  j=0; j<p2.size(); j++) p2[j]--;
        }
        else if(s1[i] == '-' && s2[i] == '+'){
            p1--;
            for(int  j=0; j<p2.size(); j++) p2[j]++;
        }
        else if(s2[i] == '?'){
            if(s1[i] == '+') p1++;
            else if(s1[i] == '-') p1--;
            vector<int> np2;
            for(int j=0; j<p2.size(); j++){
                np2.push_back(p2[j]+1);
                np2.push_back(p2[j]-1);
            }
            p2 = np2;
        }
    }
    double count = 0;
    for(int i=0; i<p2.size(); i++){
        if(p2[i] == p1) count++;
    }
    cout<<setprecision(10)<<count/p2.size()<<endl;
    return 0;
}
