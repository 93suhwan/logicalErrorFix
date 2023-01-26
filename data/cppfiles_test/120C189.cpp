#include <bits/stdc++.h>
using namespace std;
int a[200001][32];
int on[200001][32];
void solve() {
  int le, r;
  cin >> le >> r;
  int oc[32];
  for (int i = 0; i < 32; i++) {
    oc[i] = on[r][i] - on[le - 1][i];
  }
  sort(oc, oc + 32, greater<int>());
  cout << r - le + 1 - oc[0] << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < 200001; i++) {
    int c = 0;
    for (int j = 31; j >= 0; j--) {
      if (((1 << j) & i) == 0) {
        a[i][c] = 0;
      } else {
        a[i][c] = 1;
      }
      c++;
    }
  }
  for (int j = 0; j < 32; j++) {
    int c = 0;
    for (int i = 0; i < 200001; i++) {
      if (a[i][j] == 1) {
        c++;
      }
      on[i][j] = c;
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}
