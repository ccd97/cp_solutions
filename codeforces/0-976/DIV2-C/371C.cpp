#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    int nb, ns, nc; cin>>nb>>ns>>nc;
    int pb, ps, pc; cin>>pb>>ps>>pc;
    long long r; cin>>r;
    int tb=0, ts=0, tc=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'B') tb++;
        else if(s[i] == 'S') ts++;
        else if(s[i] == 'C') tc++;
    }
    long long ans = 0;
    int hhcm;
    if(tb!=0 && ts!=0 && tc!=0) hhcm = floor(min(min(nb/tb, ns/ts), nc/tc));
    else if(tb==0 && ts!=0 && tc!=0) hhcm = floor(min(ns/ts, nc/tc));
    else if(ts==0 && tb!=0 && tc!=0) hhcm = floor(min(nb/tb, nc/tc));
    else if(tc==0 && ts!=0 && tb!=0) hhcm = floor(min(ns/ts, nb/tb));
    else if(tb!=0) hhcm = floor(nb/tb);
    else if(ts!=0) hhcm = floor(ns/ts);
    else if(tc!=0) hhcm = floor(nc/tc);
    if(hhcm > 0){
        ans += hhcm; nb -= hhcm*tb; ns -= hhcm*ts; nc -= hhcm*tc;
        if(tb == 0) nb = 0; if(ts == 0) ns = 0; if(tc == 0) nc = 0;
    }
    while(nb!=0 || ns!=0 || nc!= 0){
        long long cost = (tb-(nb>tb?tb:nb))*pb + (ts-(ns>ts?ts:ns))*ps + (tc-(nc>tc?tc:nc))*pc;
        if(cost <= r){
            nb = nb>tb?nb-tb:0; ns = ns>ts?ns-ts:0; nc = nc>tc?nc-tc:0; r-=cost; ans++;
        }
        else{
            cout<<ans<<endl; return 0;
        }
    }
    long long cost1 = tb*pb + ts*ps + tc*pc;
    long long bans = 0;
    long long st = 0;
    long long ed = r/cost1 + 10;
    long long mid, rmid;
    while(st < ed){
        // cout<<st<<" "<<ed<<endl;
        mid = (st+ed)/2;
        rmid = r - mid*cost1;
        if(rmid == 0){
            bans = mid;
            st++;
        }
        else if(rmid < 0){
            ed = mid;
        }
        else{
            bans = mid;
            st = mid+1;
        }
    }
    cout<<ans+bans<<endl;
    return 0;
}
