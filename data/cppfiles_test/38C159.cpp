#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = N * 2, mod = 1e9 + 7;
const double PI = acos(-1.0), eps = 1e-6;
int T, n, m, k, c1, c2;
int a[N * 10], b[N], tot, cnt[N], s[N * 10], ans;
map<int, int> mp;
vector<int> v;
string g[N * 10];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> g[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (i - 1 >= 0 && g[i - 1][j] == 'X' && j - 1 >= 0 && g[i][j - 1] == 'X')
        a[j + 1] = 1;
  for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (s[r] - s[l] > 0)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
