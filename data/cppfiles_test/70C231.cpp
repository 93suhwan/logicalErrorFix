#include <bits/stdc++.h>
using namespace std;
const int MN = 100005;
const int mx = 500005;
const int INF = 1000000007;
const int MOD = 998244353;
int n;
char s[mx], _s[mx], t[mx];
int num[mx][30], f[30];
int tp;
vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Tc;
  for (cin >> Tc; Tc--;) {
    cin >> s;
    n = strlen(s);
    for (int i = 1; i < n + 1; i++) {
      for (int j = 0; j < 26; j++)
        num[i][j] = num[i - 1][j] + (s[i - 1] - 'a' == j);
    }
    memset(f, 0, sizeof f);
    v.clear();
    for (int i = n - 1; i >= 0; i--) {
      if (!f[s[i] - 'a']) v.push_back(s[i] - 'a');
      f[s[i] - 'a'] = 1;
    }
    int m = 0, sz = v.size(), k = sz, sn;
    bool can = 1;
    for (int u : v) {
      if (num[n][u] % k) {
        can = 0;
        break;
      }
      m += num[n][u] / k;
      k--;
    }
    if (!can) {
      cout << -1 << endl;
    } else {
      reverse(v.begin(), v.end());
      sn = 0;
      memset(f, 0, sizeof f);
      for (int u : v) {
        for (int i = 0; i < m; i++)
          if (!f[s[i] - 'a']) _s[sn++] = s[i];
        f[u] = 1;
      }
      for (int i = 0; i < n; i++)
        if (s[i] != _s[i]) {
          can = 0;
          break;
        }
      if (!can) {
        cout << -1 << endl;
      } else {
        for (int i = 0; i < m; i++) cout << s[i];
        cout << " ";
        for (int u : v) cout << char(u + 'a');
        cout << endl;
      }
    }
  }
  return 0;
}
