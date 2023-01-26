#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<vector<int>>> sums(n + 10,
                                   vector<vector<int>>(3, vector<int>(3, 0)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == i % 3 && k == s[i] - 'a') {
          sums[i + 1][i % 3][k] = sums[i][i % 3][k] + 1;
        } else {
          sums[i + 1][j][k] = sums[i][j][k];
        }
      }
    }
  };
  for (int qi = 0; qi < m; qi++) {
    int l, r;
    cin >> l >> r;
    l--;
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
      v[i] = i;
    }
    int ans = INF;
    do {
      ;
      int same = 0;
      for (int j = 0; j < 3; j++) {
        int k = v[j];
        same += sums[r][(l + j) % 3][k] - sums[l][(l + j) % 3][k];
      }
      int tans = r - l - same;
      ;
      ans = min(ans, tans);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
  }
  return 0;
}
