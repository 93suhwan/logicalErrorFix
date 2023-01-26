#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
long long n, k;
const int N = 2 * 10e5 + 1;
int max_deep = INT_MIN;
long long red = 0LL;
long long blue = 0LL;
bool visited_dfs[N];
bool visited_c[N];
bool visited_p[N];
int infected[N];
long long infected_count = 1LL;
unordered_map<int, pair<int, vector<int>>> edges;
unordered_map<int, int> parent;
unordered_map<int, vector<int>> deepest;
void find_parents() {
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_p[curr] = true;
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited_p[ch]) {
        parent[curr] = ch;
        continue;
      }
      qq.push(ch);
    }
  }
}
void dfs() {
  int depth = 0;
  edges[1].first = depth;
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_dfs[curr] = true;
    if (curr != 1) edges[curr].first = edges[parent[curr]].first + 1;
    max_deep = max(max_deep, edges[curr].first);
    deepest[edges[curr].first].push_back(curr);
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited_dfs[ch]) continue;
      qq.push(ch);
    }
  }
}
bool should_paint(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    if (infected[curr]) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      if (parent[curr] == ch) continue;
      st.push(ch);
    }
  }
  return true;
}
void color_red() {
  int i = 0;
  while (max_deep >= 0) {
    for (size_t j = 0; j < deepest[max_deep].size(); ++j) {
      if (i == k || infected_count == n) return;
      if (!should_paint(deepest[max_deep][j])) continue;
      int current = parent[deepest[max_deep][j]];
      while (current != 1) {
        if (infected[current] == true) break;
        ++infected_count;
        infected[current] = true;
        current = parent[current];
      }
      ++red, ++i;
      ++infected_count;
      infected[deepest[max_deep][j]] = true;
    }
    --max_deep;
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i += 1) {
    int u, v;
    cin >> u >> v;
    edges[u].second.push_back(v);
    edges[v].second.push_back(u);
  }
  infected[1] = true;
  find_parents();
  dfs();
  color_red();
  blue = n - infected_count;
  if (infected_count == n) {
    if (red < k && red < n - 1) {
      if (k > n / 2)
        red = n / 2;
      else
        red = k;
    }
  }
  cout << ((n - red - blue) * (red - blue)) << '\n';
  return 0;
}
