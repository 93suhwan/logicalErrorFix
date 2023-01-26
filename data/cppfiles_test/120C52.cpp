#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<vector<int>> v(200001, vector<int>(19, 0));
  for (int i = 1; i < 200001; ++i) {
    long long int p = 1;
    int c = 0;
    for (; p < 6 * 1e5; p *= 2) {
      if (i & p) {
        v[i][c] = v[i - 1][c] + 1;
      } else {
        v[i][c] = v[i - 1][c];
      }
      c++;
    }
  }
  while (t--) {
    int l, r;
    cin >> l >> r;
    int temp = INT_MIN;
    for (int i = 0; i < 19; ++i) {
      temp = max(temp, v[r][i] - v[l - 1][i]);
    }
    cout << r - l + 1 - temp << endl;
  }
  return 0;
}
