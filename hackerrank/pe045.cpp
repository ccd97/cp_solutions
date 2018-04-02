#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long n, a, b; cin>>n>>a>>b;
    if(a == 3 || b == 3){
        long n3=1, n5=1, n3i=1, n5i=1;
        while(n3 < n && n5 < n){
            if(n3 == n5) cout<<n3<<endl;
            if(n3 <= n5){
                n3i++;
                n3 = n3i*(n3i+1)/2;
            }
            else{
                n5i++;
                n5 = n5i*(3*n5i-1)/2;
            }
        }
    }
    else{
        long n5=1, n7=1, n5i=1, n7i=1;
        while(n5 < n && n7 < n){
            if(n5 == n7) cout<<n5<<endl;
            if(n5 <= n7){
                n5i++;
                n5 = n5i*(3*n5i-1)/2;
            }
            else{
                n7i++;
                n7 = n7i*(2*n7i-1);
            }
        }

    }
}
