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
vector<int> tc;
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
vector<pair<int, int>> kolorki;
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
    if (curr == 1) continue;
    int length = 0;
    int current = parent[curr];
    while (current != 1) {
      current = parent[current];
      ++length;
    }
    kolorki.push_back(make_pair(curr, length));
  }
}
void color_red() {
  sort(kolorki.begin(), kolorki.end(),
       [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
         return a.second > b.second;
       });
  for (int i = 0; i < k; i += 1) {
    if (infected_count == n) break;
    infected[kolorki[i].first] = true;
    ++red, ++infected_count;
    int current = parent[kolorki[i].first];
    while (current != 1) {
      if (infected[current]) break;
      infected[current] = true;
      current = parent[current];
      ++infected_count;
    }
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
    if (red != infected_count - 1) {
      if (red < k) {
        if (k > n / 2)
          red = n / 2;
        else
          red = k;
      }
    }
  }
  blue = max(blue, 0LL);
  if (k == 42992) cout << "RED: " << red << " BLUE: " << blue << '\n';
  cout << ((n - red - blue) * (red - blue)) << '\n';
  return 0;
}
