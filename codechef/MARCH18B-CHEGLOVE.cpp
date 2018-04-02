#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		long l[n], g[n];
		for(int i=0; i<n; i++) cin>>l[i];
		for(int i=0; i<n; i++) cin>>g[i];
		bool f1=true, f2=true;
		for(int i=0; i<n; i++) if(l[i]>g[i]) { f1 = false; break; }
		for(int i=0; i<n; i++) if(l[i]>g[n-1-i]) { f2 = false; break; }
		if(f1 && f2) cout<<"both"<<endl;
		else if(f1 && !f2) cout<<"front"<<endl;
		else if(!f1 && f2) cout<<"back"<<endl;
		else cout<<"none"<<endl;
	}
	return 0;
}
