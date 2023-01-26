#include <bits/stdc++.h>
using namespace std;
int cnt[200021][32];
int main() {
  int T, l, r;
  cin >> T;
  for (int i = (1); i <= (200021 - 1); i++)
    for (int p = (0); p <= (30); p++) cnt[i][p] = cnt[i - 1][p] + (i >> p & 1);
  while (T--) {
    cin >> l >> r;
    int mx = 0;
    for (int i = (0); i <= (30); i++) mx = max(mx, cnt[r][i] - cnt[l - 1][i]);
    cout << r - l + 1 - mx << endl;
  }
  return 0;
}
