#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	long long a, b; cin>>a>>b;
	string s; cin>>s;
	if(a == 0 && b == 0){
		cout<<"Yes"<<endl;
		return 0;
	}
	long long i_x=0, i_y=0;
	vector<pair<long, long>> pps;
	for(int i=0; i<s.size(); i++){
		switch(s[i]){
			case 'R': i_x++; break;
			case 'U': i_y++; break;
			case 'L': i_x--; break;
			case 'D': i_y--; break;
		}
		pps.push_back({i_x, i_y});
	}
	bool success = false;
	for(auto p: pps){
		if(i_x == 0 && i_y == 0){
			if(a == p.first && b == p.second){
				success = true;
				break;
			}
		}
		else if(i_x == 0){
			if(a == p.first && (b-p.second) % i_y == 0){
				if(int((b-p.second)/i_y) >= 0){
					success = true;
					break;
				}
			}
		}
		else if(i_y == 0){
			if(b == p.second && (a-p.first) % i_x == 0){
				if(int((a-p.first)/i_x) >= 0){
					success = true;
					break;
				}
			}
		}
		else if((a-p.first) % i_x != 0 || (b-p.second) % i_y != 0) continue;
		else if(int((a-p.first)/i_x) ==  int((b-p.second)/i_y)){
			if(int((a-p.first)/i_x) >= 0 && int((b-p.second)/i_y) >= 0){
				success = true;
				break;
			}
		}
	}
	if(success) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}