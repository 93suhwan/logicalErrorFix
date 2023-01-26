#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a[3];
  a[1].push_back(0);
  a[2].push_back(0);
  int x;
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> x;
      a[i].push_back(x);
    }
  }
  int table[3][n + 3];
  table[1][n + 1] = 0;
  table[2][n + 1] = 0;
  table[1][0] = 0;
  table[2][0] = 0;
  for (int j = n; j >= 1; j--) {
    table[1][j] = table[1][j + 1] + a[1][j];
  }
  for (int j = 1; j <= n; j++) {
    table[2][j] = table[2][j - 1] + a[2][j];
  }
  long long ans = INT_MAX;
  for (int j = 1; j <= n; j++) {
    long long temp = max(table[1][j + 1], table[2][j - 1]);
    if (temp < ans) ans = temp;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
