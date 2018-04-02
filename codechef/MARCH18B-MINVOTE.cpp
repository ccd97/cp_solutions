#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		long arr[n], carr[n];
		int res[n]; memset(res, 0, sizeof(res));
		for(int i=0; i<n; i++) cin>>arr[i];
		carr[0] = arr[0];
		for(int i=1; i<n; i++) carr[i] = carr[i-1] + arr[i];
		
		for(int i=0; i<n-1; i++){
			int lo = i+1, hi = n-1, mid;
			long dist;
			while(lo < hi){
				mid = lo + (hi - lo)/2;
				dist = carr[mid-1] - carr[i];
				if(dist > arr[i]) hi = mid;
				else lo = mid + 1;
			}
			for(int j=i+1; j<lo; j++) res[j]++;
			if(carr[lo-1]-carr[i] <= arr[i]) res[lo]++;
		}
		
		for(int i=1; i<n; i++){
			int lo = 0, hi = i-1, mid;
			long dist;
			while(lo < hi){
				mid = lo + (hi - lo)/2;
				dist = carr[i-1] - carr[mid];
				if(dist <= arr[i]) hi = mid;
				else lo = mid + 1;
			}
			for(int j=lo; j<i-1; j++) res[j]++;
			if(carr[i-1] - carr[lo] <= arr[i]) res[i-1]++;
		}
		
		for(int i=0; i<n; i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
