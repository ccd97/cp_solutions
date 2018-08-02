#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    unordered_set<int> used;
    vector<int> result;
    for(int i=n-1; i>=0; i--){
        if(used.find(arr[i]) == used.end()){
            result.push_back(arr[i]);
            used.insert(arr[i]);
        }
    }
    cout<<result.size()<<endl;
    for(int i=result.size()-1; i>=0; i--)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
