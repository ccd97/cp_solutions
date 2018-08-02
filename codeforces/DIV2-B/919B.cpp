#include <bits/stdc++.h>

using namespace std;

bool issum10(int n) {
   int sum = 0;
   while (n != 0) {
       sum = sum + n % 10;
       if(sum > 10) return false;
       n = n/10;
   }
   return sum == 10;
}

int main(int argc, char const *argv[]) {
    vector<int> pn;
    for(int i=19; i<11000000; i++){
        if(issum10(i)) pn.push_back(i);
    }
    int n;
    cin>>n;
    cout<<pn[n-1]<<endl;
    return 0;
}
