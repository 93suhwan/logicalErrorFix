#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool b[1 << 19];
int32_t main() {
  cin >> n >> k;
  vector<vector<long long>> c(1 << k, vector<long long>(1, 1e9));
  vector<vector<long long>> l(1 << k, vector<long long>(1, 1e9));
  vector<vector<long long>> r(1 << k, vector<long long>(1, 1e9));
  for (long long i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    l[a][0] = r[a][0] = 0;
  }
  while (c.size() > 1) {
    vector<vector<long long>> cc;
    vector<vector<long long>> ll;
    vector<vector<long long>> rr;
    for (long long i = 0; i < c.size(); i += 2) {
      vector<long long> &c1 = c[i], &c2 = c[i + 1];
      vector<long long> &l1 = l[i], &l2 = l[i + 1];
      vector<long long> &r1 = r[i], &r2 = r[i + 1];
      vector<long long> c3(2 * c1.size()), l3(2 * c1.size()), r3(2 * c1.size());
      for (long long j = 0; j < c1.size(); ++j) {
        c3[j] = c3[c1.size() + j] = min(c1[j], c2[j]);
        c3[j] = min(c3[j], r1[j] + l2[j] + 1);
        c3[c1.size() + j] = min(c3[c1.size() + j], l1[j] + r2[j] + 1);
        l3[j] = min(l1[j], (long long)c1.size() + l2[j]);
        l3[c1.size() + j] = min(l2[j], (long long)c1.size() + l1[j]);
        r3[j] = min(r2[j], (long long)c1.size() + r1[j]);
        r3[c1.size() + j] = min(r1[j], (long long)c1.size() + r2[j]);
      }
      cc.push_back(c3);
      ll.push_back(l3);
      rr.push_back(r3);
    }
    c = cc;
    l = ll;
    r = rr;
  }
  for (long long a : c[0]) cout << a << " ";
  cout << "\n";
}
