#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1010;
long long minv[Nmax][Nmax], s[Nmax];
long long a[Nmax];
int n;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (i % 2 == 1 ? 1 : -1) * a[i];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    minv[i][i - 1] = 0;
    long long now = 0;
    for (int j = i; j <= n; ++j) {
      now += (j % 2 == 1 ? 1 : -1) * a[j];
      minv[i][j] = min(minv[i][j - 1], now);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      long long lv = minv[i + 1][j - 1];
      if (i % 2 == 0 || j % 2 == 1) continue;
      long long l = a[i] + lv;
      long long r = a[j] - (s[j - 1] - s[i] - lv);
      int okl = (lv != 0), okr = (s[j - 1] - s[i] - lv != 0);
      ans += max(0LL, min(l + okl, r + okr));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_--) {
    solve();
  }
}
