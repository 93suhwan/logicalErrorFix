#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
int Logn[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char> > mp(n + 1, vector<char>(m + 1));
  vector<bool> vis(m + 1, 0);
  vector<int> v;
  for (int i = 0; i <= m; i++) mp[0][i] = '.';
  for (int i = 0; i <= n; i++) mp[i][0] = 'X';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (mp[i - 1][j] == 'X' && mp[i][j - 1] == 'X' && mp[i][j] == '.' &&
          !vis[j]) {
        vis[j] = 1;
        v.push_back(j);
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int xa, xb;
    cin >> xa >> xb;
    if (xa == xb) {
      cout << "YES\n";
      continue;
    }
    auto it = lower_bound(v.begin(), v.end(), xa + 1);
    if (it != v.end() && (*it) <= xb)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
