#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a[6], ts=0, tmp;
    for(int i=0; i<6; i++){
        cin>>tmp;
        ts += tmp;
        a[i] = tmp;
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            for(int k=0; k<6; k++){
                if(!(i == j || j == k || i == k)){
                    if(2*(a[i] + a[j] + a[k]) == ts){
                        cout<<"YES"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
