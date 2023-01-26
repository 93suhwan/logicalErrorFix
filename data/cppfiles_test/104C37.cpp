#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int a[200005];
int b[200005];
int l[200005];
int r[200005];
int n, m;
pair<int, int> res[200005];
void solve() {
  cin >> n >> m;
  long long T = 1ll * m * n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    T += a[i] - b[i];
  }
  long long sr = 0, sl = 0;
  for (int i = 1; i <= n; ++i) {
    r[i] = min(a[i], m);
    l[i] = max(0, m - b[i]);
    sr += 2 * r[i];
    sl += 2 * l[i];
  }
  if (T <= sl) {
    cout << abs(T - sl) << "\n";
    for (int i = 1; i <= n; ++i) cout << l[i] << " " << m - l[i] << "\n";
    return;
  }
  if (T >= sr) {
    cout << abs(T - sr) << "\n";
    for (int i = 1; i <= n; ++i) cout << r[i] << " " << m - r[i] << "\n";
    return;
  }
  T -= sl;
  for (int i = 1; i <= n; ++i) {
    long long first = min(1ll * r[i] - l[i], T / 2);
    T -= first * 2;
    first += l[i];
    res[i] = {first, m - first};
  }
  cout << abs(T) << "\n";
  for (int i = 1; i <= n; ++i)
    cout << res[i].first << " " << res[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
