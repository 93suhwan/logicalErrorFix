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
        z = i;
        qw = j;
        l--;
        r--;
        z--;
        qw++;
        while (l >= 1 && r >= 1 && a[l][r] == '*' && z >= 1 && qw <= m &&
               a[z][qw] == '*') {
          p++;
          if (p >= k) {
            long long lr = l;
            long long rr = r;
            us[i][j] = 1;
            while (lr != i && rr != j) {
              us[lr][rr] = 1;
              lr++;
              rr++;
            }
            lr = z;
            rr = qw;
            while (lr != i && rr != j) {
              us[lr][rr] = 1;
              lr++;
              rr--;
            }
          }
          l--;
          r--;
          z--;
          qw++;
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
