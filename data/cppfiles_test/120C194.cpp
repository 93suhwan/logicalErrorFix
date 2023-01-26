#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 1) return x;
  return ((y & 1) ? (x * pow(x, y - 1)) : (pow(x * x, y / 2)));
}
int Dp[200001][20];
void solve() {
  int l, r;
  cin >> l >> r;
  vector<long long> tes(20, 0);
  int maxi = 0;
  for (int i = 0; i < 20; i++) {
    maxi = max(maxi, Dp[r][i] - Dp[l - 1][i]);
  }
  cout << (r - l + 1 - maxi) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < 200001; i++) {
    int tes = i, ki = 0;
    while (tes) {
      Dp[i][ki++] += (tes % 2);
      tes /= 2;
    }
    for (int j = 0; j < 20; j++) {
      Dp[i][j] += Dp[i - 1][j];
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}
