#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int cnt[32][N + 10];
int main() {
  for (int i = 1; i <= N; i++) {
    int n = i, t = 0;
    while (n > 0) {
      cnt[t][i] = cnt[t][i - 1] + n % 2;
      t++;
      n /= 2;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int k[32] = {};
    for (int i = 0; i < 32; i++) {
      k[i] = cnt[i][r] - cnt[i][l - 1];
    }
    int res = 0;
    for (int i = 0; i < 32; i++) {
      res = max(res, k[i]);
    }
    cout << (r - l + 1) - res << '\n';
  }
}
