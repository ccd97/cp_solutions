#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n,i;
        cin>>n;
        for (i = 2; i <= sqrt(n); i++)
        {
            if (n%i == 0)
            {
                n = n / i;
                i--;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
