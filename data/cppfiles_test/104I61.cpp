#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mxn = 2e5;
long long inf = 1e16;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<array<long long, 2> > a(n);
  long long s1 = 0, s2 = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    s1 += a[i][0];
    s2 += a[i][1];
  }
  sort(a.begin(), a.end());
  vector<pair<long long, long long> > ve(n);
  for (long long i = 0; i < n; i++) {
    if (s1 == s2) {
      long long j = m / 2;
      j = m - j;
      if (a[i][0] >= j) {
        ve[i] = {j, m - j};
        s1 -= j;
        s2 -= (m - j);
      } else {
        ve[i] = {a[i][0], m - a[i][0]};
        s1 -= a[i][0];
        s2 -= (m - a[i][0]);
      }
    } else if (s1 > s2) {
      long long k = s1 - s2;
      if (k >= m) {
        if (a[i][0] >= m) {
          ve[i] = {m, 0};
          s1 -= m;
        } else {
          ve[i] = {a[i][0], m - a[i][0]};
          s1 -= a[i][0];
          s2 -= (m - a[i][0]);
        }
      } else {
        long long l = m - k;
        l = l / 2;
        l = m - l;
        if ((k + l) <= a[i][0]) {
          ve[i] = {k + l, m - k - l};
          s1 -= k + l;
          s2 -= (m - k - l);
        } else {
          ve[i] = {a[i][0], m - a[i][0]};
          s1 -= a[i][0];
          s2 -= m - a[i][0];
        }
      }
    } else {
      long long k = s2 - s1;
      if (k >= m) {
        if (a[i][1] >= m) {
          ve[i] = {0, m};
          s2 -= m;
        } else {
          ve[i] = {m - a[i][1], a[i][1]};
          s2 -= a[i][1];
          s1 -= (m - a[i][1]);
        }
      } else {
        long long l = m - k;
        l = l / 2;
        if ((k + l) <= a[i][1]) {
          ve[i] = {m - k - l, k + l};
          s2 -= k + l;
          s1 -= (m - k - l);
        } else {
          ve[i] = {m - a[i][1], a[i][1]};
          s2 -= a[i][1];
          s1 -= m - a[i][1];
        }
      }
    }
  }
  cout << abs(s1 - s2) << "\n";
  for (long long i = 0; i < n; i++)
    cout << ve[i].first << " " << ve[i].second << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
