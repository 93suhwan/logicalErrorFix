#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int st[N * 2][40];
void solve() {
  for (int i = 1; i < N; i++) {
    for (int j = 30; j >= 0; j--) {
      int t = i >> j & 1;
      if (!t) st[i][j]++;
      st[i + 1][j] += st[i][j];
    }
  }
}
int main() {
  solve();
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int minn = 1e9;
    for (int i = 30; i >= 0; i--) {
      minn = min(minn, st[r][i] - st[l - 1][i]);
    }
    cout << minn << endl;
  }
  return 0;
}
