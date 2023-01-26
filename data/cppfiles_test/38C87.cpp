#include <bits/stdc++.h>
using namespace std;
string ch[1000010];
vector<int> a[1000010], e[1000010];
int f[1000010], pres[1000010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int i;
  for (i = 1; i <= n; ++i) cin >> ch[i];
  int j;
  for (i = 1; i <= n; ++i) {
    a[i].resize(m + 1);
    for (j = 1; j <= m; ++j) {
      if (ch[i][j - 1] == 'X') a[i][j] = 1;
    }
  }
  for (i = 2; i <= n; ++i) {
    for (j = 2; j <= m; ++j) {
      if (a[i - 1][j] && a[i][j - 1]) f[j] = 1;
    }
  }
  for (i = 2; i <= m; ++i) pres[i] = pres[i - 1] + f[i];
  int q;
  cin >> q;
  for (i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "YES\n";
      continue;
    }
    if (pres[r] - pres[l])
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
