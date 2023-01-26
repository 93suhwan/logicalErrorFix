#include <bits/stdc++.h>
const long long N = 2e5 + 100;
const long long INF = 1e9;
const long long inf = -1e9;
const long long MOD = 998244353;
using namespace std;
long long binpow(long long a, long long x) {
  if (x == 0) return 1;
  if (x % 2 == 1) return (a * binpow(a, x - 1));
  long long p = binpow(a, x / 2);
  return (p * p);
}
char a[1010][1010];
long long n, m, k, us[1010][1010], l, r, p, z, qw;
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      us[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '*') {
        l = i;
        r = j;
        long long p = 0;
        while (l < n && r < m && a[l][r] == '*') {
          l++;
          r++;
          p++;
          z = l;
          qw = r;
          long long cnt = 0;
          while (z >= 2 && qw < m && cnt < p && a[z][qw] == '*' && p >= k) {
            z--;
            qw++;
            cnt++;
          }
          if (cnt == p) {
            z = l;
            qw = r;
            long long cnt = 0;
            while (z >= 2 && qw < m && cnt < p && a[z][qw] == '*' && p >= k) {
              z--;
              qw++;
              cnt++;
              us[z][qw] = 1;
            }
            cnt = 0;
            z = l;
            qw = r;
            us[l][r] = 1;
            while (z >= 2 && qw >= 2 && cnt <= p && a[z][qw] == '*') {
              cnt++;
              z--;
              qw--;
              us[z][qw] = 1;
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '*' && us[i][j] == 0) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int o = 1;
  cin >> o;
  while (o--) {
    solve();
  }
}
