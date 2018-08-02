#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  string s; cin>>s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  if(rs == s)
    cout<<s<<endl;
  else
    cout<<s<<rs<<endl;
  return 0;
}
