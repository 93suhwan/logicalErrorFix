#include <bits/stdc++.h>
using namespace std;
const long double inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    set<long long> xx;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      xx.insert(a[i]);
    }
    long long id = 0;
    map<long long, long long> tt;
    for (long long x : xx) {
      tt[x] = id++;
    }
    for (long long i = 0; i < n; ++i) a[i] = tt[a[i]];
    vector<long long> idd(n);
    for (long long i = 0; i < n; ++i) idd[a[i]] = i;
    long long res = 0;
    long long i = 0;
    while (i < n) {
      long long cur = idd[i];
      while (cur + 1 < n && a[cur + 1] == a[cur] + 1) {
        ++i;
        ++cur;
      }
      ++i;
      res++;
    }
    if (res <= k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
