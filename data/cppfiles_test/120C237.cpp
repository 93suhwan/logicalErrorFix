#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int cnt[N][30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 30; ++j) {
      cnt[i][j] = cnt[i - 1][j];
      if (i & (1 << j)) cnt[i][j]++;
    }
  }
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int l, r;
    cin >> l >> r;
    int mx = 0;
    for (int j = 0; j < 30; ++j) {
      mx = max(mx, cnt[r][j] - cnt[l - 1][j]);
    }
    cout << r - l + 1 - mx << '\n';
  }
}
