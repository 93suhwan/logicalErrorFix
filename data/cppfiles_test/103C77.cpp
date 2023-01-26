#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
ostream &operator<<(ostream &os, min_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, pair<F, S> P) {
  return os << P.first << " " << P.second;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> matrix) {
  os << "\n";
  for (int i = 0; i < (int)matrix.size(); i++) {
    for (int j = 0; j < (int)matrix[i].size(); j++) {
      os << matrix[i][j] << " ";
    }
    os << "\n";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, map<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, multimap<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
const int MAX_N = 4e6 + 10;
int adj[MAX_N];
int ns[MAX_N];
int dist[MAX_N];
int cycle = 0;
int dfs(int node, int dep) {
  if (ns[node] != 0) {
    if (dist[node] == 0) {
      int len = dep - ns[node];
      dist[node] = len;
      cycle = 1;
    }
    return dist[node];
  }
  ns[node] = dep;
  int val = dfs(adj[node], dep + 1);
  if (cycle) {
    if (dist[node] == 0) {
      dist[node] = val;
    } else {
      cycle = 0;
    }
  } else {
    dist[node] = val + 1;
  }
  return dist[node];
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= (int)n * m; i++) {
    dist[i] = 0;
    adj[i] = 0;
    ns[i] = 0;
  }
  vector<vector<char>> arr(n, vector<char>(m));
  for (int i = 0; i < (int)n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < (int)m; j++) {
      arr[i][j] = str[j];
    }
  }
  auto get_id = [&](int i, int j) -> int { return i * m + j + 1; };
  auto get_nxt = [&](int i, int j) -> int {
    int ni = i, nj = j;
    if (arr[i][j] == 'R') {
      nj++;
    } else if (arr[i][j] == 'L') {
      nj--;
    } else if (arr[i][j] == 'U') {
      ni--;
    } else {
      ni++;
    }
    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
      return get_id(ni, nj);
    } else {
      return get_id(i, j);
    }
  };
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      int cur = get_id(i, j);
      int nxt = get_nxt(i, j);
      adj[cur] = nxt;
    }
  }
  for (int i = 1; i <= (int)n * m; i++) {
    if (ns[i] == 0) {
      dfs(i, 1);
    }
  }
  int best_node = -1;
  int max_dep = -1;
  for (int i = 1; i <= (int)n * m; i++) {
    if (dist[i] > max_dep) {
      max_dep = dist[i];
      best_node = i;
    }
  }
  best_node--;
  int x = best_node / m + 1;
  int y = best_node % m + 1;
  cout << x << " " << y << " " << max_dep << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dist, 0, sizeof(dist));
  memset(adj, 0, sizeof(adj));
  memset(ns, 0, sizeof(ns));
  int no_of_testcases = 1;
  cin >> no_of_testcases;
  for (int tc = 1; tc <= no_of_testcases; tc++) {
    solve();
  }
  return 0;
}
