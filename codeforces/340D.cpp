#include <bits/stdc++.h>

using namespace std;

int lis(int arr[], int n){
    vector<int> lisa;
    for(int i=0; i<n; i++){
       auto it = lower_bound(lisa.begin(), lisa.end(), arr[i]);
       if(it == lisa.end()) lisa.push_back(arr[i]);
       else *it = arr[i];
    }
    return lisa.size();
}

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<lis(arr, n)<<endl;
    return 0;
}
