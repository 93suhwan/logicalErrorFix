#include <bits/stdc++.h>
using namespace std;
long long up(long long x, long long n) {
  if (x % n == 0)
    return x / n;
  else
    return x / n + 1;
}
long long gcd(long long a, long long b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long g, n;
    cin >> g >> n;
    vector<vector<pair<long long, long long> > > a(n), b(g);
    for (long long i = 0; i < g; i++) {
      for (long long j = 0; j < n; j++) {
        long long x;
        cin >> x;
        a[j].push_back(make_pair(x, i));
        b[i].push_back(make_pair(x, j));
      }
    }
    for (long long i = 0; i < g; i++) {
      sort(b[i].begin(), b[i].end());
      reverse(b[i].begin(), b[i].end());
    }
    for (long long i = 0; i < n; i++) {
      sort(a[i].begin(), a[i].end());
      reverse(a[i].begin(), a[i].end());
    }
    map<long long, long long> m;
    vector<long long> c;
    long long mi = 1e18, ans = -1;
    for (long long i = 0; i < n; i++) {
      m[a[i][0].second]++;
      mi = min(a[i][0].first, mi);
      c.push_back(a[i][0].first);
    }
    sort(c.begin(), c.end());
    if (m.size() <= n - 1)
      cout << mi;
    else {
      long long mx = -1, fir = 1e18, fr1 = 0, fr2 = 0;
      for (long long i = 0; i < g; i++) {
        if (mx <= b[i][1].first) {
          if (mx == b[i][1].first && fir < b[i][0].first) {
            fir = b[i][0].first;
            fr2 = b[i][0].second;
          }
          mx = b[i][1].first;
          fr1 = b[i][1].second;
        }
      }
      ans = mx;
      for (long long i = 0; i < n; i++)
        if (a[i][0].second != fr1 && a[i][0].second != fr2)
          ans = min(ans, a[i][0].first);
      cout << ans;
    }
    cout << "\n";
  }
  return 0;
}
