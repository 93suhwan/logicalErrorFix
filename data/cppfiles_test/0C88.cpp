#include <bits/stdc++.h>
using namespace std;
int t, ans = 0, tot = 0, kk = 0;
const int mxn = 2e7 + 10, mod = 1e9 + 7;
signed main() {
  int n, m, a, b, c, d, e, i, j, k, sm = 0, sm1 = 0, cn = 0, cn1 = 0, mx = -1e9,
                                    mn = 1e9;
  string s, ss, sr, sa;
  bool f = false, ff = true;
  char ch;
  cin >> n >> m;
  pair<vector<int>, int> pr[n + 1];
  for (i = 1; i <= n; i++) {
    for (j = 0; j < m; j++) {
      cin >> ch;
      if (j % 2 == 0)
        pr[i].first.push_back((int)ch);
      else
        pr[i].first.push_back(-(int)ch);
    }
    pr[i].second = i;
  }
  sort(pr + 1, pr + n + 1);
  for (i = 1; i <= n; i++) cout << pr[i].second << " ";
  cout << "\n";
}
