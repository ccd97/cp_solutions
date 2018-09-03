#include <iostream>
using namespace std;

int height(int n) {
    int i,h =1;
    for (i=0;i<n;i++){
        if(i%2==0) h*=2;
        else h+= 1;
    }
    return h;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
