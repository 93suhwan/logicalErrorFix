#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long h[N], e[N], nx[N], idx;
long long k, T, t, n, m, ans, cnt;
long long a[N];
bool vis[N], flag = false;
priority_queue<long long, vector<long long>, greater<long long> > q;
char s1[N], s2[N];
void solve() {
  for (long long i = 1; i <= n; i++) {
    if (s1[i] == s2[1]) {
      long long pos = 1;
      for (long long j = i; j <= n && pos <= m; j++, pos++) {
        if (s1[j] != s2[pos]) break;
        for (long long k = pos, l = j; k <= m && l >= 1; k++, l--) {
          if (k == m && s2[k] == s1[l]) {
            flag = true;
            return;
          }
          if (s2[k] != s1[l]) break;
        }
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    flag = false;
    cin >> s1 + 1 >> s2 + 1;
    n = strlen(s1 + 1);
    m = strlen(s2 + 1);
    solve();
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
