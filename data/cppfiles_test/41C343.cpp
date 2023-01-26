#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, Q;
  cin >> n >> Q;
  string ss = "abc";
  vector<string> v;
  do {
    v.push_back(ss);
  } while (next_permutation(ss.begin(), ss.end()));
  string s;
  cin >> s;
  vector<vector<int> > vv(v.size(), vector<int>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    int inx = 0;
    int j = 0;
    while (j < n) {
      if (v[i][inx] != s[j]) vv[i][j]++;
      if (j) vv[i][j] += vv[i][j - 1];
      j++;
      inx++;
      if (inx >= 3) inx = 0;
    }
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = (int)1e9;
    for (int i = 0; i < v.size(); i++) {
      int tm;
      if (l) {
        tm = vv[i][r] - vv[i][l - 1];
      } else
        tm = vv[i][r];
      ans = min(ans, tm);
    }
    cout << ans << endl;
  }
  return 0;
}
