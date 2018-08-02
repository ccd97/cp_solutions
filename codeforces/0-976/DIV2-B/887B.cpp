#include <bits/stdc++.h>

using namespace std;

template <typename T>
std::set<T> getUnion(const std::set<T>& a, const std::set<T>& b)
{
  std::set<T> result = a;
  result.insert(b.begin(), b.end());
  return result;
}

template <typename T>
std::set<T> getUnion3(const std::set<T>& a, const std::set<T>& b, const std::set<T>& c)
{
  std::set<T> result = a;
  result.insert(b.begin(), b.end());
  result.insert(c.begin(), c.end());
  return result;
}

int main(int argc, char const *argv[]) {
    int n, tmp; cin>>n;
    unordered_map<int, set<int>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            cin>>tmp;
            auto it = m.find(tmp);
            if(it == m.end()) {
                set<int> zzz {i};
                m.emplace(tmp, zzz);
            }
            else it->second.insert(i);
        }
    }
    for(int i=1; i<10; i++){
        if(m.find(i) == m.end()){
            cout<<i-1<<endl;
            return 0;
        }
    }
    for(int i=1; i<10; i++){
        auto it1 = m.find(i);
        for(int j=0; j<10; j++){
            auto it2 = m.find(j);
            if(it2 == m.end()){
                cout<<i*10+j-1<<endl;
                return 0;
            }
            auto sze = getUnion(it1->second, it2->second).size();
            if(sze < 2){
                cout<<i*10+j-1<<endl;
                return 0;
            }
        }
    }
    for(int i=1; i<10; i++){
        auto it1 = m.find(i);
        for(int j=0; j<10; j++){
            auto it2 = m.find(j);
            if(it2 == m.end()){
                cout<<i*100+(j-1)*10+9<<endl;
                return 0;
            }
            auto sze = getUnion(it1->second, it2->second).size();
            if(sze < 2){
                cout<<i*100+(j-1)*10+9<<endl;
                return 0;
            }
            for(int k=0; k<10; k++){
                auto it3 = m.find(k);
                if(it3 == m.end()){
                    cout<<i*100+j*10+(k-1)<<endl;
                    return 0;
                }
                auto sze = getUnion3(it1->second, it2->second, it3->second).size();
                if(sze < 3){
                    cout<<i*100+j*10+(k-1)<<endl;
                    return 0;
                }
            }
        }
        cout<<999<<endl;
    }

}
