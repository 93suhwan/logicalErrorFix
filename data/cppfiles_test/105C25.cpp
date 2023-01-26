#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
const long long INF = 1e18;
struct Dish {
  int a, b, id;
};
struct Seg {
  int l, r, id;
  bool operator<(const Seg& oth) const { return r < oth.r; }
};
vector<Dish> v[MAXN];
int a[MAXN], b[MAXN], m[MAXN];
int suba[MAXN], subb[MAXN];
inline void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = b[i] = m[i] = suba[i] = subb[i] = 0;
  vector<int> val;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> m[i];
    v[a[i] + b[i] - m[i]].push_back({a[i], b[i], i});
    val.push_back(a[i] + b[i] - m[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  int ans = (!v[0].empty());
  for (auto c : v[0]) {
    suba[c.id] = c.a;
    subb[c.id] = c.b;
  }
  for (auto i : val) {
    if (i == 0) continue;
    vector<Seg> s;
    for (auto c : v[i]) {
      int x = c.a, y = c.b;
      s.push_back({max(0, i - y), min(x, i), c.id});
    }
    sort(s.begin(), s.end());
    int ed = -1;
    int x = 0, y = 0;
    for (auto c : s) {
      if (c.l > ed) {
        x = c.r, y = i - x;
        ans++;
        suba[c.id] = a[c.id] - x;
        subb[c.id] = b[c.id] - y;
        ed = c.r;
      } else {
        suba[c.id] = a[c.id] - x;
        subb[c.id] = b[c.id] - y;
      }
    }
  }
  for (auto i : val) v[i].clear();
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) cout << suba[i] << " " << subb[i] << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
