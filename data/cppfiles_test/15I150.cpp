#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
string s[20];
long long vis[20][20], fnl[20][20], ct = 1;
vector<pair<long long, long long> > v1, v2, v;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k, mn = -1;
    cin >> n >> m >> k;
    memset(vis, 0, sizeof(vis));
    for (long long i = 0; i < n; i++) cin >> s[i];
    for (long long i = n - 1; i >= 0; i--) {
      for (long long j = 0; j < m; j++) {
        long long a = i, b = j, c = i, d = j, p = -1, fl = 0, pp = 0, qq = -1;
        if (s[a][b] != '*') continue;
        while (a >= 0 && a < n && b >= 0 && b < m && c >= 0 && c < n &&
               d >= 0 && d < m) {
          if (s[a][b] == '*' && s[c][d] == '*')
            p++;
          else
            break;
          if (!vis[a][b]) {
            vis[a][b] = 1;
            pp = a;
            qq = b;
            fl = 1;
          }
          if (!vis[c][d]) {
            vis[c][d] = 1;
            pp = c;
            qq = d;
            fl = 1;
          }
          a--;
          b--;
          c--;
          d++;
        }
        if (fl) {
          if (mn == -1) mn = p;
          mn = min(mn, p);
        }
      }
    }
    if (mn == -1) {
      cout << "NO" << endl;
      return 0;
    }
    if (mn >= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    cout << endl;
  }
}
