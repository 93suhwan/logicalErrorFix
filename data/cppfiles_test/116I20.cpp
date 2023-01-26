#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  map<int, int> occ;
  vector<int> invalid_chars(K);
  for (int i = 0; i < N; i++) {
    occ.clear();
    for (auto j : A[i]) {
      occ[j]++;
    }
    for (auto j : occ) {
      if (j.second > 1) {
        invalid_chars[j.first] = 1;
      }
    }
  }
  vector<set<int>> classes(K);
  for (int i = 0; i < N; i++) {
    bool bad = false;
    for (auto j : A[i]) {
      if (invalid_chars[j]) {
        bad = true;
      }
    }
    if (bad) {
      continue;
    }
    for (auto j : A[i]) {
      classes[j].emplace(i);
    }
  }
  vector<int> par(K);
  iota(begin(par), end(par), 0);
  function<int(int)> Find = [&](int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
  };
  const auto Merge = [&](int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    par[x] = y;
    if (classes[x].size() > classes[y].size()) {
      swap(classes[x], classes[y]);
    }
    for (auto i : classes[x]) {
      classes[y].emplace(i);
    }
    classes[x].clear();
    return;
  };
  for (int i = 0; i < N; i++) {
    bool bad = false;
    for (auto j : A[i]) {
      if (invalid_chars[j]) {
        bad = true;
      }
    }
    if (bad) {
      continue;
    }
    for (auto j : A[i]) {
      Merge(j, A[i][0]);
    }
  }
  const int MAX = 3e5 + 5;
  vector<int> item(MAX);
  for (int ch = 0; ch < K; ch++) {
    if (invalid_chars[ch]) {
      continue;
    }
    if (Find(ch) != ch) {
      continue;
    }
    if (classes[ch].empty()) {
      item[1] += 1;
      continue;
    }
    set<int> nodes;
    set<pair<int, int>> edges;
    auto &members = classes[ch];
    for (auto i : members) {
      for (int j = 0; j < int(A[i].size()); j++) {
        nodes.emplace(A[i][j]);
      }
      for (int j = 1; j < int(A[i].size()); j++) {
        edges.emplace(A[i][j - 1], A[i][j]);
      }
    }
    if (edges.size() + 1 != nodes.size()) {
      continue;
    }
    map<int, int> indeg;
    map<int, int> outdeg;
    for (auto [u, v] : edges) {
      outdeg[u]++;
      indeg[v]++;
    }
    array<array<int, 2>, 2> cnt = {};
    for (auto u : nodes) {
      if (indeg[u] > 1 || outdeg[u] > 1) {
        continue;
      }
      cnt[indeg[u]][outdeg[u]] += 1;
    }
    if (nodes.size() == 1 || (cnt[0][1] == 1 && cnt[1][0] == 1 &&
                              cnt[1][1] == int(nodes.size()) - 2)) {
      item[nodes.size()] += 1;
    }
  }
  vector<pair<int, int>> items;
  for (int i = 0; i < MAX; i++) {
    if (item[i] > 0) {
      items.emplace_back(i, item[i]);
    }
  }
  using lint = long long;
  const lint MOD = 998244353;
  vector<lint> dp(M + 1);
  dp[0] = 1;
  for (int i = 0; i < M; i++) {
    for (auto [val, way] : items) {
      if (i + val <= M) {
        dp[i + val] += 1ll * dp[i] * way % MOD;
        dp[i + val] %= MOD;
      }
    }
  }
  cout << dp[M] << '\n';
  return 0;
}
