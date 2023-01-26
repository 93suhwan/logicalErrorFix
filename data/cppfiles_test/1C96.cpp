#include <bits/stdc++.h>
using namespace std;
long long cnt[5][5];
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    cnt[x % 4][y % 4]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 2; i += 2) {
    for (int j = 0; j <= 2; j += 2) {
      long long v = cnt[i][j];
      ans += v * (v - 1) * (v - 2) / 6;
      for (int k = 0; k <= 2; k += 2) {
        for (int l = 0; l <= 2; l += 2) {
          long long w = cnt[k][l];
          if (k == i && l == j) continue;
          ans += v * w * (w - 1) / 2;
        }
      }
    }
  }
  cout << ans << endl;
}
