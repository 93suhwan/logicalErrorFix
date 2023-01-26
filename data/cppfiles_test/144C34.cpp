#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = ceil(1.0 * n / m);
  int b = floor(1.0 * n / m);
  int sum = n - m * b;
  vector<int> tnum(m + 10, b);
  int d = 0;
  for (int i = 1; i <= m; i++) {
    if (sum == 0) break;
    tnum[i]++;
    d += tnum[i];
    sum--;
  }
  int pos = 0;
  for (int i = 0; i < k; i++) {
    pos += d;
    for (int j = 1; j <= m; j++) {
      cout << tnum[j] << " ";
      for (int p = 0; p < tnum[j]; p++) {
        pos++;
        pos = (pos - 1) % n + 1;
        cout << pos << " ";
      }
      cout << "\n";
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
