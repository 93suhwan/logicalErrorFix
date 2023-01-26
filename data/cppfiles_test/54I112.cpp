#include <bits/stdc++.h>
using namespace std;
void debug_all() { cerr << "]\n"; }
template <typename T, typename... Types>
void debug_all(T var1, Types... var2) {
  cerr << ' ' << var1 << ' ';
  debug_all(var2...);
}
int p0, p1;
bool flag;
void solve(int p, int pos, vector<int>& ans, vector<vector<pair<int, int>>>& uv,
           vector<vector<pair<int, int>>>& vu) {
  if (ans[pos] != -1) {
    if (ans[pos] != p) {
      flag = true;
    }
    return;
  }
  ans[pos] = p;
  if (p == 0) {
    p0++;
  } else {
    p1++;
  }
  for (auto it : uv[pos]) {
    if (p == 0) {
      solve(abs(1 - it.second), it.first, ans, uv, vu);
    } else {
      solve(it.second, it.first, ans, uv, vu);
    }
  }
  for (auto it : vu[pos]) {
    if (p == 0) {
      solve(abs(1 - it.second), it.first, ans, uv, vu);
    } else {
      solve(it.second, it.first, ans, uv, vu);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc, n, m, best;
  int u, v, p;
  string s;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    best = 0;
    flag = false;
    vector<vector<pair<int, int>>> uv(n), vu(n);
    vector<int> ans(n, -1);
    while (m--) {
      cin >> u >> v >> s;
      u--;
      v--;
      if (s[0] == 'i') {
        p = 0;
      } else {
        p = 1;
      }
      uv[u].push_back({v, p});
      vu[v].push_back({u, p});
    }
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1 && uv[i].size() != 0) {
        p0 = 0;
        p1 = 0;
        solve(0, i, ans, uv, vu);
        best += max(p0, p1);
      }
      if (ans[i] == -1) {
        best++;
      }
    }
    if (flag) {
      best = -1;
    }
    cout << best << endl;
  }
  return 0;
}
