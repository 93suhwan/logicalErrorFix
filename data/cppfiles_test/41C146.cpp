#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string v[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<int> > store(6, vector<int>(s.length() + 1));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j <= s.length(); j++) store[i][j] = 0;
  }
  for (int i = 0; i < 6; i++) {
    int j = 1, k = 0;
    while (j <= s.length()) {
      if (s[j - 1] != v[i][k]) {
        store[i][j] += store[i][j - 1] + 1;
      } else {
        store[i][j] = store[i][j - 1];
      }
      j++;
      k = (k + 1) % 3;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = INT_MAX;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, store[i][r] - store[i][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
