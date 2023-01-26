#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
const int M = 2000;
int n;
int a[N];
struct pythonArray {
  int v[M * 4];
  int &operator[](int x) { return v[x + M]; }
} f[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(f, 0x3f, sizeof f);
  f[1][a[1]] = f[1][-a[1]] = a[1];
  for (int i = 2; i <= n; ++i) {
    for (int j = -1000; j <= 1000; ++j) {
      f[i][j] =
          min(f[i][j], f[i - 1][j - a[i]] + max(a[i] - f[i - 1][j - a[i]], 0));
      f[i][j] =
          min(f[i][j], f[i - 1][j + a[i]] + max(a[i] - f[i - 1][j + a[i]], 0));
    }
  }
  int ans = 0x3f3f3f3f;
  for (int j = -1000; j <= 1000; ++j) ans = min(ans, f[n][j]);
  cout << ans << "\n";
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
