#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    int width[n];
    for(int i = 0;i < n;i++){
       cin >> width[i];
    }
    for(int i = 0; i < t; i++){
        int a,b;
        cin >> a >> b;
        int lowest = width[a];
        for(int j = a+1; j<=b; j++){
            if(width[j]<lowest) lowest = width[j];
        }
        cout<<lowest<<endl;
    }
    return 0;
}
