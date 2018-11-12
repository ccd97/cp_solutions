#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long n, l, x, y, num; cin>>n>>l>>x>>y;
    long arr[n]; unordered_set<long> st;
    for(int i=0; i<n; i++){
        cin>>num; arr[i] = num;
        st.insert(num);
    }

    bool xposs = false, yposs = false;
    for(int i=0; i<n-1 and !xposs; i++){
        if(st.find(arr[i] + x) != st.end())
            xposs = true;
    }
    for(int i=0; i<n-1 and !yposs; i++){
        if(st.find(arr[i] + y) != st.end())
            yposs = true;
    }

    long mn = *min_element(arr, arr+n);
    if(xposs and yposs) cout<<0<<endl;
    else if(xposs) cout<<1<<endl<<mn+y<<endl;
    else if(yposs) cout<<1<<endl<<mn+x<<endl;
    else{
        unordered_set<long> pmx;
        for(int i=0; i<n; i++){
            if(arr[i]+x<=l) pmx.insert(arr[i]+x);
            if(arr[i]-x>=0) pmx.insert(arr[i]-x);
        }
        int oneval = -1;
        for(int i=0; i<n and oneval==-1; i++){
            if((arr[i]+y<=l) and pmx.find(arr[i]+y) != pmx.end())
                oneval = arr[i]+y;
            if((arr[i]-y>=0) and pmx.find(arr[i]-y) != pmx.end())
                oneval = arr[i]-y;
        }

        if(oneval != -1) cout<<1<<endl<<oneval<<endl;
        else cout<<2<<endl<<mn+x<<" "<<mn+y<<endl;
    }

    return 0;
}
