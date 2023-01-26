#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m;
  cin >> m;
  int a1[m];
  int a2[m];
  for (int i = 0; i < m; i += 1) {
    cin >> a1[i];
  }
  for (int i = 0; i < m; i += 1) {
    cin >> a2[i];
  }
  int flag[2][m];
  for (int i = 0; i < 2; i += 1) {
    for (int j = 0; j < m; j += 1) {
      flag[i][j] = 1;
    }
  }
  int last = a2[m - 1];
  partial_sum(a2, a2 + m, a2);
  int pos = -1;
  flag[0][0] = 0;
  for (int i = 1; i < m - 1; i += 1) {
    if (a1[i + 1] < a2[i]) {
      pos = i;
      break;
    } else {
      flag[0][i] = 0;
    }
  }
  flag[1][m - 1] = 0;
  int first = a1[0];
  partial_sum(a1, a1 + m, a1);
  if (pos == -1) {
    cout << a2[m - 1] - last << endl;
  } else {
    int ans1 = a1[m - 1] - a1[pos];
    int ans2 = a2[pos - 1];
    cout << max(ans1, ans2) << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
