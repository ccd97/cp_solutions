#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m, k; cin>>n>>m>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    if(k==1) {
        cout<<n<<endl;
        return 0;
    }
    if(n==1 || k > m || n < k) {
        cout<<0<<endl;
        return 0;
    }
    sort(arr, arr+n);
    list<int> arrl(arr, arr+n);
    int ans = 0;
    list<int>::iterator i = arrl.begin();
    list<int>::iterator j = arrl.begin();
    advance(j, k-1);
    while(i != arrl.end() && j != arrl.end()){
        if(*j - *i + 1 <= m){
            ans++;
            auto ptd = j;
            j++;
            arrl.erase(ptd);
        }
        else{
            i++;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
