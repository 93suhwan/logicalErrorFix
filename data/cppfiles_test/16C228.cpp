#include <bits/stdc++.h>
void solve() {
  int n;
  std::cin >> n;
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a == 0) continue;
    st.insert(std::make_pair(a, i + 1));
  }
  std::vector<std::pair<int, int>> res;
  while (st.size() > 1) {
    auto mn = st.begin();
    auto mx = st.end();
    mx--;
    int v1 = (*mn).first, v2 = (*mx).first;
    int id1 = (*mn).second, id2 = (*mx).second;
    st.erase(mn);
    st.erase(mx);
    res.push_back({id1, id2});
    if (v1 - 1) st.insert(std::make_pair(v1 - 1, id1));
    if (v2 - 1) st.insert(std::make_pair(v2 - 1, id2));
  }
  std::cout << res.size() << std::endl;
  for (auto r : res) {
    std::cout << r.first << " " << r.second << std::endl;
  }
}
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
