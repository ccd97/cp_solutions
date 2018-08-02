#include <bits/stdc++.h>

using namespace std;

short g[1000006];
vector<int> sg[10];

int getDigPro(int d){
  int res = 1;
  while(d > 0){
    if(d%10 != 0)
      res *= d%10;
    d /= 10;
  }
  return res;
}

void preCompute(){
  for(int i=1; i<1000006; i++){
    if(i<10) g[i] = i;
    else{
      g[i] = g[getDigPro(i)];
    }
  }
  for(int i=1; i<1000006; i++){
    sg[g[i]].push_back(i);
  }
}

int main(int argc, char const *argv[]) {
  preCompute();
  int q; cin>>q;
  while(q--){
    int l, r, k; cin>>l>>r>>k;
    int lb = lower_bound(sg[k].begin(), sg[k].end(), l) - sg[k].begin();
    int ub = upper_bound(sg[k].begin(), sg[k].end(), r) - sg[k].begin();
    cout<<ub-lb<<endl;
  }
}
