#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000001;
const long long LLINF = 9223372036854775807;
const long long M = 998244353;
const double EPS = 1e-8;
long long n, m;
vector<vector<long long> > a;
bool floorr;
vector<long long> flr;
void fill(long long i, long long j, long long i1, long long j1) {
  set<long long> res = {0, 1, 2, 3, 4, 5, 7};
  if (i - 1 >= 0)
    res.erase(a[i - 1][j]);
  else if (floorr)
    res.erase(flr[j]);
  if (i + 1 < n) res.erase(a[i + 1][j]);
  if (j - 1 >= 0) res.erase(a[i][j - 1]);
  if (j + 1 < m) res.erase(a[i][j + 1]);
  if (i1 - 1 >= 0)
    res.erase(a[i1 - 1][j1]);
  else if (floorr)
    res.erase(flr[j1]);
  if (i1 + 1 < n) res.erase(a[i1 + 1][j1]);
  if (j1 - 1 >= 0) res.erase(a[i1][j1 - 1]);
  if (j1 + 1 < m) res.erase(a[i1][j1 + 1]);
  a[i][j] = *res.begin();
  a[i1][j1] = *res.begin();
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> n >> m >> k;
    long long h = (n - (k % n)) % n;
    long long w = m - (((k + n - 1) / n) * 2);
    long long mx = (m / 2) * n;
    floorr = false;
    if (n % 2 && (w > 0 && w % 2 == 0) && k > w / 2) {
      k -= m / 2;
      --n;
      floorr = true;
    } else if (n % 2 && (w > 0 && w % 2 == 0)) {
      cout << "NO"
           << "\n";
      continue;
    }
    h = (n - (k % n)) % n;
    w = m - (((k + n - 1) / n) * 2);
    mx = (m / 2) * n;
    if ((k > mx) || (h % 2) || (w % 2 && n % 2)) {
      cout << "NO"
           << "\n";
      continue;
    } else {
      cout << "YES"
           << "\n";
      long long cr = 0;
      a.clear();
      a.resize(n, vector<long long>(m, -1));
      if (floorr) {
        flr.resize(m);
        for (long long i = 0; i + 1 < m; i += 2) {
          flr[i] = cr;
          flr[i + 1] = cr;
          ++cr;
        }
      }
      for (long long i = 0; i < k; i++)
        fill(i % n, 2 * (i / n), i % n, 2 * (i / n) + 1);
      if (w % 2) {
        for (long long i = 0; i + 1 < n; i += 2) fill(i, m - 1, i + 1, m - 1);
        for (long long j = 1; j < w; j++) {
          for (long long i = 0; i + 1 < n; i += 2)
            fill(i, m - 1 - j, i + 1, m - 1 - j);
        }
      } else {
        for (long long j = 0; j < w; j++) {
          for (long long i = 0; i + 1 < n; i += 2)
            fill(i, m - 1 - j, i + 1, m - 1 - j);
        }
      }
      if (k % n != 0) {
        for (long long i = k % n; i + 1 < n; i += 2) {
          fill(i, 2 * (k / n), i + 1, 2 * (k / n));
          fill(i, 2 * (k / n) + 1, i + 1, 2 * (k / n) + 1);
        }
      }
      if (floorr) {
        for (long long j = 0; j < m; j++) cout << char('a' + flr[j]);
        cout << "\n";
      }
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) cout << char('a' + a[i][j]);
        cout << "\n";
      }
    }
  }
  return 0;
}
