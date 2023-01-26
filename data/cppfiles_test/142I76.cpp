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
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < g; j++) {
          long long num = a[i][j].first, sto = a[i][j].second, rem = mi, x = 0;
          if (a[i][0].first == rem) x++, rem = c[x];
          if (num < rem) {
            rem = num;
            if (x)
              x = 0;
            else
              x = -1;
          }
          long long o = b[sto][0].first, ad = b[sto][0].second;
          if (o == num && b[sto].size() > 1)
            o = b[sto][1].first, ad = b[sto][1].second;
          if (a[ad][0].first == rem) x++, rem = c[x];
          if (o < rem) rem = o;
          ans = max(ans, rem);
        }
      }
      cout << ans;
    }
    cout << "\n";
  }
  return 0;
}
