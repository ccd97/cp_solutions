#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k; cin>>n>>k;
    vector<int> dpos[10];
    string num; cin>>num;
    for(unsigned int i=0; i<num.size(); i++){
        dpos[num[i]-'0'].push_back(i);
    }

    unordered_set<int> resp[10];
    long bestans = LONG_MAX;
    int nor = -1;

    for(int i=0; i<10; i++){
        int p1 = i-1, p2 = i+1;
        int ck = dpos[i].size();
        long ans = 0;
        while(ck < k){
            int p3 = -1, p4 = -1;
            if(p1>=0 and !dpos[p1].empty())
                p3 = dpos[p1].size()-1;
            if(p2<=9 and !dpos[p2].empty())
                p4 = 0;

            while(p4 != -1 and p4 < dpos[p2].size() and ck < k){
                ck++; ans += abs(i - p2);
                resp[i].insert(dpos[p2][p4]);
                p4++;
            }

            while(p3 >= 0 and ck < k){
                ck++; ans += abs(i - p1);
                resp[i].insert(dpos[p1][p3]);
                p3--;
            }

            p1--;
            p2++;
        }

        if(ans < bestans){
            bestans = ans;
            nor = i;
        }
        else if(ans == bestans){
            string bs = "", cs = "";
            for(unsigned int j=0; j<num.size(); j++)
                if(resp[nor].find(j) != resp[nor].end()) bs += ('0' + nor);
                else bs += num[j];
            for(unsigned int j=0; j<num.size(); j++)
                if(resp[i].find(j) != resp[i].end()) cs += ('0' + i);
                else cs += num[j];
            if(cs < bs){
                bestans = ans;
                nor = i;
            }
        }
    }

    cout<<bestans<<endl;

    for(unsigned int i=0; i<num.size(); i++){
        if(resp[nor].find(i) != resp[nor].end())
            cout<<nor;
        else
            cout<<num[i];
    }

    cout<<endl;

    return 0;
}
