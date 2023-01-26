#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int n;
int a[109];
int calc(int x, int y) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int res = MOD;
    for (int j = 0; j <= x; ++j) {
      for (int k = 0; k <= y; ++k) {
        if (a[i] - j - k * 2 < 0 || (a[i] - j - k * 2) % 3) continue;
        res = min(res, (a[i] - j - k * 2) / 3);
      }
    }
    cnt = max(cnt, res);
  }
  return cnt + x + y;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << min({calc(0, 0), calc(1, 0), calc(0, 1), calc(1, 1), calc(0, 2)})
         << "\n";
  }
}
