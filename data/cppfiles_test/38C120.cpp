#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
string s[maxn];
int pref[maxn]{};
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int j = 1; j < m; ++j) {
    for (int i = 1; i < n; ++i) {
      if (s[i][j - 1] == 'X' && s[i - 1][j] == 'X') {
        pref[j] = 1;
        break;
      }
    }
    pref[j] += pref[j - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (pref[a - 1] == pref[b - 1] ? "YES\n" : "NO\n");
  }
  return 0;
}
