#include <bits/stdc++.h>
using namespace std;
const int MAXX = 2e5 + 10;
int T, n;
set<pair<int, int>> st;
vector<pair<int, int>> vec;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    vec.clear();
    for (int i = 0, x; i < n; i++) cin >> x, st.insert({x, i + 1});
    while (st.size() >= 2) {
      auto it1 = st.end(), it2 = it1;
      --it1, --it2, --it2;
      int x = it1->first, y = it2->first;
      for (int i = 0; i < it2->first; i++)
        vec.push_back({it1->second, it2->second});
      st.erase({x, it1->second});
      st.erase({y, it2->second});
      if (x > y) st.insert({x - y, it1->first});
    }
    cout << vec.size() << '\n';
    for (auto x : vec) cout << x.first << " " << x.second << '\n';
  }
}
