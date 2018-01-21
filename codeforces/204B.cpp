#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;
	long t1, t2;
	unordered_map<long, int> fc, bc, sc;

	for(int i=0; i<n; i++){
		cin>>t1>>t2;
		if(t1 == t2){
			auto it = sc.find(t1);
			if(it == sc.end()) sc.emplace(t1, 1);
			else it->second++;
			continue;
		}
		auto it1 = fc.find(t1);
		auto it2 = bc.find(t2);
		if(it1 == fc.end()) fc.emplace(t1, 1);
		else it1->second++;
		if(it2 == bc.end()) bc.emplace(t2, 1);
		else it2->second++;
	}

	int half = ceil(n/2.0);
	int minc = (sc.size() == 1 && sc.begin()->second == n)?0:INT_MAX;
	for(auto pfc : fc){
		auto sit = sc.find(pfc.first);
		int nsc = (sit==sc.end())?0:sit->second;
		if(pfc.second + nsc >= half){
			minc = 0;
		}
		else{
			auto it = bc.find(pfc.first);
			if(it != bc.end() && it->second >= (half - pfc.second - nsc)){
				minc = min(minc, half - pfc.second - nsc);
			}
		}
	}
	for(auto pbc : bc){
		auto sit = sc.find(pbc.first);
		int nsc = (sit==sc.end())?0:sit->second;
		if(fc.find(pbc.first) == fc.end() && pbc.second + nsc >= half){
			minc = min(minc, half - nsc);
		}
	}
	if(minc == INT_MAX) cout<<-1<<endl;
	else cout<<minc<<endl;
	return 0;

}
