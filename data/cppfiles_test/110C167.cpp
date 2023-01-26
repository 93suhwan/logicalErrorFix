#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void run_case() {
  int N;
  cin >> N;
  vector<vector<int>> edges(N + 2);
  vector<int> indegree(N + 2);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= x; j++) {
      int y;
      cin >> y;
      edges[y].push_back(i);
      ++indegree[i];
    }
  }
  set<int> q;
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0) {
      q.insert(i);
    }
  };
  int cnt = 0, ans = 1, t = 1;
  while (!q.empty()) {
    auto it = q.lower_bound(ans);
    if (it == q.end()) {
      t++;
      ans = 1;
      continue;
    }
    int u = *it;
    q.erase(it);
    ans = u + 1;
    ++cnt;
    for (auto y : edges[u]) {
      --indegree[y];
      if (indegree[y] == 0) {
        q.insert(y);
      }
    }
  }
  if (cnt != N) {
    cout << "-1"
         << "\n";
  } else {
    cout << t << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests--) {
    run_case();
  }
  return 0;
}
