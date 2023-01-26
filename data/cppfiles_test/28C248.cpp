#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
const double eps = 1e-8;
void solve() {
  long long a[4];
  long long x = 0, y = 0, ans = 10010000;
  for (int i = 1; i <= 3; ++i) {
    cin >> a[i];
    a[i] = a[i] % 10 + 10;
  }
  y = a[1] + a[2] * 2 + a[3] * 3;
  for (int i = 0; i <= a[1]; ++i) {
    for (int j = 0; j <= a[2]; ++j) {
      for (int k = 0; k <= a[3]; ++k) {
        x = i + j * 2 + k * 3;
        ans = min(ans, abs((y - x) - x));
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
