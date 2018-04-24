#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned int arr[20][20];
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            cin>>arr[i][j];
        }
    }
    unsigned int maxv = 0;
    for(int i=0; i<20; i++){
        for(int j=0; j<17; j++){
            maxv = max(maxv, arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3]);
        }
    }
    for(int i=0; i<17; i++){
        for(int j=0; j<20; j++){
            maxv = max(maxv, arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j]);
        }
    }
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i+3 < 20 && j+3 < 20){
                maxv = max(maxv, arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3]);
            }
            if(i+3 < 20 && j-3 >= 0){
                maxv = max(maxv, arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3]);
            }
        }
    }
    cout<<maxv<<endl;
    return 0;
}
