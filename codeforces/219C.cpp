#include <bits/stdc++.h>

using namespace std;

long n; int k; string s;

int main(int argc, char const *argv[]) {
    cin>>n>>k>>s;
    if(k == 2){
        string s1="", s2="";
        int chs1 =0, chs2 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ((i%2==0)?'A':'B')) chs1++;
            if(s[i] != ((i%2==0)?'B':'A')) chs2++;
            s1 += (i%2==0)?'A':'B';
            s2 += (i%2==0)?'B':'A';
        }
        cout<<min(chs1, chs2)<<endl;
        cout<<((chs1<chs2)?s1:s2)<<endl;
        return 0;
    }
    string cs = ""; cs += s[0];
    vector<int> ccs = {1};
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]) ccs.back()++;
        else {
            cs += s[i];
            ccs.push_back(1);
        }
    }
    long changes = 0;
    string finals = "";
    for(int i=0; i<cs.size(); i++){
        if(ccs[i] == 1){
            finals += cs[i];
        }
        else if(ccs[i] % 2 == 0){
            if(i == 0){
                char torep = cs[i+1];
                if(ccs.size() == 1){
                    if(cs[i] - 'A' + 2 > k && cs[i] != 'A') torep = (cs[i]-1);
                    else torep = (cs[i]+1);
                }
                for(int j=0; j<ccs[i]/2; j++){
                    finals += torep;
                    finals += cs[i];
                    changes++;
                }
            }
            else{
                char torep = cs[i-1];
                if(torep == cs[i+1]){
                    for(char j=0; j<k; j++){
                        if(cs[i+1] != (char)('A' + j) && cs[i] != (char)('A' + j)){
                            torep = (char)('A' + j);
                            break;
                        }
                    }
                }
                for(int j=0; j<ccs[i]/2; j++){
                    finals += cs[i];
                    finals += torep;
                    changes++;
                }
            }
        }
        else {
            char torep = (i == 0) ? cs[i+1] : cs[i-1];
            if(ccs.size() == 1){
                if(cs[i] - 'A' + 2 > k && cs[i] != 'A') torep = (cs[i]-1);
                else torep = (cs[i]+1);
            }
            for(int j=0; j<ccs[i]/2; j++){
                finals += cs[i];
                finals += torep;
                changes++;
            }
            finals += cs[i];

        }
    }
    cout<<changes<<endl;
    cout<<finals<<endl;
    return 0;
}
