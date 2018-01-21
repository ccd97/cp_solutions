#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	long n, m; cin>>n>>m;
	if(log2(m) >= n){
		cout<<m%(1<<n)<<endl;
	}
	else{
		cout<<m<<endl;
	}
	return 0;
}
