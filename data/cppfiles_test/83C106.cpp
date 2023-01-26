#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int c[N][N], f[N];
char a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= n + 1; ++j) c[i][j] = 0;
  for (int i = n; i >= 1; --i)
    for (int j = n; j >= 1; --j)
      if (a[i] == a[j]) c[i][j] = c[i + 1][j + 1] + 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = 0;
    for (int j = 1; j < i; ++j)
      if (a[j + c[i][j]] < a[i + c[i][j]]) f[i] = max(f[i], f[j] - c[i][j]);
    f[i] += n - i + 1;
  }
  cout << *max_element(f + 1, f + n + 1) << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
