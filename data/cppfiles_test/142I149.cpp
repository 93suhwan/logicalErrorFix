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
    multiset<long long> c;
    for (long long i = 0; i < n; i++) {
      m[a[i][0].second]++;
      c.insert(a[i][0].first);
    }
    auto sm = c.begin();
    long long mi = (*sm), ans = -1;
    if (m.size() <= n - 1)
      cout << mi;
    else {
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < g; j++) {
          long long num = a[i][j].first, sto = a[i][j].second;
          long long o = b[sto][0].first, ad = b[sto][0].second;
          if (o == num) {
            if (b[sto].size() > 1) o = b[sto][1].first, ad = b[sto][1].second;
          }
          c.erase(c.find(a[ad][0].first));
          c.insert(o);
          auto sm = c.begin();
          mi = (*sm);
          ans = max(ans, mi);
          c.insert(a[ad][0].first);
          c.erase(c.find(o));
        }
      }
      cout << ans;
    }
    cout << "\n";
  }
  return 0;
}
