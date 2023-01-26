#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int MAXN = 2e5 + 10;
const int INF = 1e5;
int n, m;
map<pair<int, int>, bool> mp;
vector<int> ver;
bool mark[MAXN];
bool check() {
  int cnt = 0;
  for (auto i : ver) {
    for (auto j : ver) {
      if (i == j) continue;
      int x = min(i, j);
      int y = max(i, j);
      cnt += (mp[{x, y}] ? 1 : 0);
    }
  }
  if (cnt == 10 || cnt == 0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    mp[{u, v}] = true;
  }
  for (int i = 1; i <= INF; i++) {
    ver.clear();
    for (int j = 0; j < 5; j++) {
      int x = rng() % n + 1;
      while (mark[x]) {
        x = x % n + 1;
      }
      ver.push_back(x);
      mark[x] = true;
    }
    if (check()) {
      for (auto j : ver) {
        cout << j << ' ';
      }
      return 0;
    }
    for (auto j : ver) {
      mark[j] = false;
    }
  }
  cout << -1 << '\n';
  return 0;
}
