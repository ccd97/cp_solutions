#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, a; cin>>n;
	int ans = INT_MIN;
	while(n--){
		cin>>a;
		if(a <= 0) max(ans, a);
		auto root = round(sqrt(a));
		if(root*root != a && a > ans) ans = a;
	}
	cout<<ans<<endl;
	return 0;
}
