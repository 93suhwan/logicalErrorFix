#include <bits/stdc++.h>
using namespace std;
int a[20][200005];
void solve() {
  int l, r;
  cin >> l >> r;
  int maxi = 0;
  for (int i = 0; i < 20; i++) maxi = max(maxi, a[i][r] - a[i][l - 1]);
  cout << (r - l + 1) - maxi << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j < 20; j++) {
      a[j][i] += a[j][i - 1];
      if ((i >> j) & 1) a[j][i]++;
    }
  }
  while (t--) solve();
  return 0;
}
