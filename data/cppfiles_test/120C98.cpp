#include <bits/stdc++.h>
using namespace std;
long long T;
long long cnt[1000000][32];
int main() {
  long long n, m;
  cin >> T;
  for (int i = 0; i <= 200000 + 5; i++) {
    for (int j = 0; j < 32; j++) cnt[i][j] = ((i >> j) & 1) + cnt[i - 1][j];
  }
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 1e9 + 7;
    for (int i = 0; i < 32; i++)
      ans = min(ans, r - l + 1 - cnt[r][i] + cnt[l - 1][i]);
    cout << ans << '\n';
  }
}
