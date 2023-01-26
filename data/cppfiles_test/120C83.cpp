#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  vector<vector<int>> a(20, vector<int>(200001, 0));
  for (int i = 1; i < 200001; i++) {
    int x = 2;
    int y = i;
    for (int j = 0; j < 20; j++) {
      if (y % 2 != 0) {
        a[j][i] = 1;
      }
      y = y / 2;
    }
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 1; j < 200001; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  while (t--) {
    int l, r;
    cin >> l >> r;
    int z = 0;
    for (int i = 0; i < 20; i++) {
      z = max(z, a[i][r] - a[i][l - 1]);
    }
    cout << r - l - z + 1 << endl;
  }
}
