#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int MAXN = 2e5 + 10;
const int INF = 1e6;
int n, m;
map<pair<int, int>, bool> mp;
int a[5];
bool mark[MAXN];
bool check() {
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (mp[{a[i], a[j]}]) cnt++;
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
    mp[{u, v}] = true;
    mp[{v, u}] = true;
  }
  for (int i = 1; i <= INF; i++) {
    for (int j = 0; j < 5; j++) {
      int x = rng() % n + 1;
      while (mark[x]) {
        x = rng() % n + 1;
      }
      a[j] = x;
      mark[x] = true;
    }
    if (check()) {
      for (int j = 0; j < 5; j++) {
        cout << a[j] << ' ';
      }
      cout << '\n';
      return 0;
    }
    for (int j = 0; j < 5; j++) {
      mark[a[j]] = false;
    }
  }
  cout << -1 << '\n';
  return 0;
}
