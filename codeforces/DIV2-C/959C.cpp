#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    if(n<6) cout<<-1<<endl;
    else{
        for(int i=1; i<=n-6; i++){
            cout<<i<<" "<<i+1<<endl;
        }
        cout<<n-5<<" "<<n-4<<endl;
        cout<<n-5<<" "<<n-3<<endl;
        cout<<n-5<<" "<<n-2<<endl;
        cout<<n-3<<" "<<n-1<<endl;
        cout<<n-3<<" "<<n-0<<endl;
    }
    for(int i=1; i<n; i++){
        cout<<1<<" "<<i+1<<endl;
    }
    return 0;
}
