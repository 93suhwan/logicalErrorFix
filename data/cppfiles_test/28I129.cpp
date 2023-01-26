#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt[n + 1];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    int v = (i - a[i] + 1 + n) % n;
    if (v == 0) v = n;
    cnt[v]++;
  }
  int c = 0;
  for (int i = 1; i <= n; i++) c += cnt[i] >= n - 2 * m;
  cout << c << ' ';
  for (int i = 1; i <= n; i++)
    if (cnt[i] >= n - 2 * m) cout << i - 1 << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
