#include <bits/stdc++.h>
using namespace std;
int ans[1005][1005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  int mx = ceil(log(n) / log(k));
  for (int c = 1, s = 1; c <= mx; c++, s *= k) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if ((j - 1) / s != (i - 1) / s) {
          ans[i][j] = c;
        }
      }
    }
  }
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << ans[i][j] << ' ';
    }
  }
  return 0;
}
