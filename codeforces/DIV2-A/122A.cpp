#include <bits/stdc++.h>

using namespace std;

std::vector<int> ln;

bool checkLucky(int n){
    if(n == 0 || n == 1) return false;
    bool notdlucky = false;
    int di = n;
    while(di != 0){
        if(di % 10 == 4 || di % 10 == 7){
            di /= 10;
        }
        else {
            notdlucky = true;
            break;
        }
    }
    if(!notdlucky) return true;
    else return false;
}

bool isPossibleLucky(int n){
    for(int i=0; i<ln.size(); i++){
        if(ln[i] == n || n%ln[i] == 0) return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    for(int i=1; i<1005; i++){
        if(checkLucky(i)){
            ln.push_back(i);
        }
    }
    if(isPossibleLucky(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
