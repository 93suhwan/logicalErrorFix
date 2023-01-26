#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
int a[MAX];
int psa[MAX][32];
void solve() {
  int l, r;
  cin >> l >> r;
  int m = 0;
  for (int i = 0; i <= 31; i++) {
    m = max(m, psa[r][i] - psa[l - 1][i]);
  }
  int x = r - l + 1 - m;
  cout << x << "\n";
  return;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= MAX - 1; i++) {
    vector<int> v;
    int x = i;
    while (x > 0) {
      v.push_back(x % 2);
      x /= 2;
    }
    for (int j = 0; j <= 31; j++) {
      psa[i][j] += psa[i - 1][j];
    }
    for (int j = 0; j <= v.size() - 1; j++) {
      psa[i][j] += v[j];
    }
  }
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
