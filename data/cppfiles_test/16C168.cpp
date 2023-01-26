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
    st.clear();
    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      if (x) st.insert({-x, i});
    }
    while (st.size() >= 2) {
      pair<int, int> it1 = *st.begin();
      st.erase(st.begin());
      pair<int, int> it2 = *st.begin();
      st.erase(st.begin());
      int x = it1.first, y = it2.first;
      vec.push_back({it1.second, it2.second});
      x++, y++;
      if (x < 0) st.insert({x, it1.second});
      if (y < 0) st.insert({y, it2.second});
    }
    cout << vec.size() << '\n';
    for (auto x : vec) cout << x.first << " " << x.second << '\n';
  }
}
