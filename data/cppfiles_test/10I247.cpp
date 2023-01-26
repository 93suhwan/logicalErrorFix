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
  for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
  sort(a + 1, a + n + 1);
  c[a[1].second] = 1;
  int color = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i].first == a[i - 1].first) {
      if (color < k)
        c[a[i].second] = ++color;
      else
        c[a[i].second] = 0;
    } else
      c[a[i].second] = 1, color = 1;
  }
  for (int i = 1; i <= n; ++i) cout << c[i] << ' ';
  cout << '\n';
}
int main() {
  file();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
