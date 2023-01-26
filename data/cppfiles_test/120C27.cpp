#include <bits/stdc++.h>
using namespace std;
int N = (int)2e5 + 5;
int pre[20][(int)2e5 + 5];
int main() {
  for (int i = 0; i < 20; i++) {
    int cnt = 0;
    for (int j = 1; j < N; j++) {
      pre[i][j] = pre[i][j - 1];
      if (!((j >> i) & 1)) pre[i][j]++;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int res = r - l + 1;
    for (int i = 0; i < 20; i++) res = min(res, pre[i][r] - pre[i][l - 1]);
    cout << res << "\n";
  }
  return 0;
}
