#include <iostream>
#include <algorithm>
using namespace std;
struct array {
    int item;
    int idx;
    bool operator< (const array &b) const {
        if (item == b.item) return idx < b.idx;
        else return item > b.item;
    }
};

int main() {
    int n;
    cin>>n;
    array a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].item;
        a[i].idx = i;
    }
    sort(a,a+n);
    int min = 1000000;
    for(int i=0;i<n-1;i++){
        if(a[i].item == a[i+1].item){
            if(a[i+1].idx - a[i].idx < min)
                min = a[i+1].idx - a[i].idx;
        }
    }
    if(min >= 1000000 ) min = -1;
    cout<<min<<endl;

}
