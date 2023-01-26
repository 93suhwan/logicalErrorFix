#include <bits/stdc++.h>
using namespace std;
const int w = 1e5 + 5;
long long mod = 1e9 + 7;
int a[w];
int main() {
  int i, j;
  int n;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  vector<vector<int> > upd(8192);
  for (i = 0; i < 8192; i++) upd[i].push_back(0);
  vector<int> dp(8192, 8192);
  dp[0] = 0;
  for (i = 0; i < n; i++) {
    for (int x : upd[a[i]]) {
      int p = dp[x ^ a[i]];
      if (p > a[i]) dp[x ^ a[i]] = a[i];
      for (j = a[i] + 1; j < p; j++) upd[j].push_back(x ^ a[i]);
    }
    upd[a[i]].clear();
  }
  vector<int> x;
  for (i = 0; i < 8192; i++)
    if (dp[i] != 8192) x.push_back(i);
  cout << x.size() << endl;
  for (int u : x) cout << u << " ";
  return 0;
}
