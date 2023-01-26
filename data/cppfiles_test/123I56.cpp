#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
unordered_map<int, pair<int, vector<int>>> edges;
unordered_map<int, int> parent;
unordered_map<int, vector<int>> deepest;
long long n, k;
const int N = 2 * 10e5 + 1;
int max_deep = INT_MIN;
bool visited[N];
bool vs[N];
void find_parents() {
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    vs[curr] = true;
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (vs[ch]) {
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
    visited[curr] = true;
    if (curr != 1) edges[curr].first = edges[parent[curr]].first + 1;
    max_deep = max(max_deep, edges[curr].first);
    deepest[edges[curr].first].push_back(curr);
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited[ch]) {
        parent[curr] = ch;
        continue;
      }
      qq.push(ch);
    }
  }
}
unordered_map<int, bool> red;
bool vst[N];
bool scan_children(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    vst[curr] = true;
    if (red[curr] == true) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      if (vst[ch]) continue;
      st.push(ch);
    }
  }
  return true;
}
bool should_paint(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    if (red[curr] == true) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      if (parent[curr] == ch) continue;
      st.push(ch);
    }
  }
  return true;
}
long long r = 0LL;
void color_red() {
  int i = 0;
  int y = -1;
  while (max_deep >= 0) {
    for (size_t j = 0; j < deepest[max_deep].size(); ++j) {
      if (i == k || i == n / 2) {
        y = j;
        return;
      }
      if (!should_paint(deepest[max_deep][j])) continue;
      ++r;
      red[deepest[max_deep][j]] = true;
      ++i;
    }
    --max_deep;
  }
  if (i < n / 2) {
    r = n / 2;
  }
}
long long blue = 0LL;
void color_blue() {
  int best = n / 2;
  for (size_t i = 0; i < deepest[max_deep].size(); ++i) {
    int curr = deepest[max_deep][i];
    if (deepest[max_deep][i] == deepest[max_deep].back() && max_deep > 0)
      --max_deep;
    if (scan_children(curr)) ++blue;
    if (blue == best) break;
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
  find_parents();
  dfs();
  color_red();
  color_blue();
  cout << static_cast<long long>(((n - r - blue) * (r - blue))) << '\n';
  return 0;
}
