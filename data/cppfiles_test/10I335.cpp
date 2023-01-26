#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const ll RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, k;
pii a[N];
int d[N], ans[N];
int c[N];
void file() {
  {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
  };
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
}
void solve() {
  cin >> n >> k;
  memset(d, 0, sizeof d);
  for (int i = 1; i <= n; ++i)
    cin >> a[i].first, a[i].second = i, d[a[i].first]++;
  int num = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > k)
      num += k;
    else
      num += d[i];
  }
  num /= k;
  set<int> s[N];
  int cnt = 0;
  sort(a + 1, a + n + 1);
  int color = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i].first == a[i - 1].first) {
      if (s[a[i].first].find(color) == s[a[i].first].end()) {
        ans[a[i].second] = color;
        s[a[i].first].insert(color++);
        if (color > k) {
          if (++cnt > num) break;
          color = 1;
        }
      } else
        ans[a[i].second] = 0;
    } else {
      ans[a[i].second] = color;
      s[a[i].first].insert(color++);
      if (color > k) {
        if (++cnt > num) break;
        color = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  file();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
