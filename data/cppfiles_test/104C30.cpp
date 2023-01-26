#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int _i = 0; _i < t; _i++) {
    long long n, m;
    cin >> n >> m;
    long long diff = 0;
    tuple<long long, long long, long long, int> d[n];
    pair<long long, long long> res[n];
    for (int i = 0; i < n; i++) {
      long long a, b;
      cin >> a >> b;
      res[i].first = a;
      res[i].second = b;
      long long budget = m;
      if (a < m) {
        b -= budget - a;
        budget -= budget - a;
      }
      if (b < budget) {
        a -= budget - b;
        budget -= budget - b;
      }
      d[i] = {budget, a, b, i};
      diff += a;
      diff -= b;
    }
    sort(d, d + n);
    for (int i = 0; i < n; i++) {
      long long& budget = get<0>(d[i]);
      long long& a = get<1>(d[i]);
      long long& b = get<2>(d[i]);
      int ind = get<3>(d[i]);
      long long da = max(0ll, min(diff, min(a, budget)));
      a -= da;
      budget -= da;
      diff -= da;
      long long db = max(0ll, min(-diff, min(b, budget)));
      b -= db;
      budget -= db;
      diff += db;
      a -= budget / 2 + budget % 2;
      diff -= budget / 2 + budget % 2;
      b -= budget / 2;
      diff += budget / 2;
      res[ind].first -= a;
      res[ind].second -= b;
    }
    cout << abs(diff) << endl;
    for (int i = 0; i < n; i++) {
      cout << res[i].first << " " << res[i].second << endl;
    }
  }
  return 0;
}
