#include <bits/stdc++.h>
using namespace std;
struct disjoint_set {
  vector<int_fast32_t> size;
  vector<int_fast32_t> parent;
  disjoint_set(int_fast32_t n) : size(n, 1), parent(n) {
    for (int_fast32_t i = 0; i < n; i++) parent[i] = i;
  }
  int_fast32_t get_root(int_fast32_t idx) {
    if (parent[idx] != idx) parent[idx] = get_root(parent[idx]);
    return parent[idx];
  }
  void join(int_fast32_t a, int_fast32_t b) {
    int_fast32_t r_a = get_root(a), r_b = get_root(b);
    if (r_a == r_b) return;
    if (size[r_a] < size[r_b]) swap(r_a, r_b);
    size[r_a] += size[r_b];
    parent[r_b] = r_a;
  }
};
void solve() {
  int_fast32_t n, m1, m2;
  cin >> n >> m1 >> m2;
  disjoint_set m_set(n);
  disjoint_set d_set(n);
  for (int_fast32_t i = 0; i < m1; i++) {
    int_fast32_t a, b;
    cin >> a >> b;
    a--;
    b--;
    m_set.join(a, b);
  }
  for (int_fast32_t i = 0; i < m2; i++) {
    int_fast32_t a, b;
    cin >> a >> b;
    a--;
    b--;
    d_set.join(a, b);
  }
  vector<pair<int_fast32_t, int_fast32_t>> ans;
  for (int_fast32_t i = 1; i < n; i++) {
    if (m_set.get_root(i) == m_set.get_root(0)) continue;
    if (d_set.get_root(i) == d_set.get_root(0)) continue;
    ans.push_back({1, i + 1});
    m_set.join(0, i);
    d_set.join(0, i);
  }
  vector<int_fast32_t> m_set_nd, d_set_nd;
  for (int_fast32_t i = 1; i < n; i++) {
    if (m_set.get_root(i) != m_set.get_root(0)) m_set_nd.push_back(i);
    if (d_set.get_root(i) != d_set.get_root(0)) d_set_nd.push_back(i);
  }
  while (!m_set_nd.empty() && !d_set_nd.empty()) {
    if (m_set.get_root(m_set_nd.back()) == m_set.get_root(0)) {
      m_set_nd.pop_back();
      continue;
    }
    if (d_set.get_root(d_set_nd.back()) == d_set.get_root(0)) {
      d_set_nd.pop_back();
      continue;
    }
    if (m_set_nd.empty() || d_set_nd.empty()) break;
    ans.push_back({m_set_nd.back() + 1, d_set_nd.back() + 1});
    m_set.join(m_set_nd.back(), d_set_nd.back());
    d_set.join(m_set_nd.back(), d_set_nd.back());
  }
  cout << ans.size() << "\n";
  for (pair<int_fast32_t, int_fast32_t>& p : ans)
    cout << p.first << " " << p.second << " \n";
  return;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::setprecision(10);
  solve();
  return 0;
}
