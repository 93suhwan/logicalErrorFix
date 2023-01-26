#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int _i = 0; _i < t; _i++) {
    long long n, m;
    cin >> n >> m;
    long long diff = 0;
    tuple<long long, long long, int> d[n];
    long long a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      diff += a[i];
      diff -= b[i];
      d[i] = {a[i], b[i], i};
    }
    sort(d, d + n);
    vector<tuple<int, long long, long long>> res;
    for (int i = 0; i < n; i++) {
      long long ai = get<0>(d[i]);
      long long bi = get<1>(d[i]);
      long long da = 0;
      long long db = 0;
      long long budget = m;
      da = max(0ll, min(diff, min(get<0>(d[i]), budget)));
      budget -= da;
      db = max(0ll, min(-diff, min(get<1>(d[i]), budget)));
      budget -= db;
      if (ai - da < budget / 2 + budget % 2) {
        budget -= ai - da;
        da += ai - da;
        db += budget;
      } else if (bi - db < budget / 2) {
        budget -= bi - db;
        db += bi - db;
        da += budget;
      } else {
        da += budget / 2 + budget % 2;
        db += budget / 2;
      }
      diff += db - da;
      res.push_back({get<2>(d[i]), da, db});
    }
    sort(res.begin(), res.end());
    cout << abs(diff) << endl;
    for (int i = 0; i < n; i++) {
      cout << get<1>(res[i]) << " " << get<2>(res[i]) << endl;
    }
  }
  return 0;
}
