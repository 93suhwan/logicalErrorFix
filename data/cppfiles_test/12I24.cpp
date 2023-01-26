#include <bits/stdc++.h>
using namespace std;
struct func {
  long long a, b;
  long long value(long long x) { return a * x + b; }
  bool operator<(const func &ot) const {
    return a > ot.a || (a == ot.a && b < ot.b);
  }
};
double intersect(func x, func y) { return (x.b - y.b) / (y.a - x.a); }
long long n, m;
bool a[2002][2002];
long long dmin[2002][2002];
int32_t main() {
  cin.tie(0);
  ios_base::sync_with_stdio();
  cin >> n >> m;
  n++, m++;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      char x;
      cin >> x;
      a[i][j] = (x == '1');
      dmin[i][j] = 1e18;
    }
  }
  vector<long long> last(m + 1, 0);
  for (long long i = 1; i <= n; ++i) {
    vector<func> v(0);
    vector<func> s(0);
    for (long long j = 1; j <= m; ++j) {
      if (a[i][j]) last[j] = i;
      if (last[j]) {
        long long xp = last[j], yp = j;
        func val = {-2 * yp, xp * xp + yp * yp - 2 * xp * i};
        v.push_back(val);
      }
    }
    if (!v.size()) continue;
    s.push_back(v[0]);
    for (long long j = 1; j < v.size(); ++j) {
      if (v[j].a != v[j - 1].a) {
        while (s.size() > 1 && intersect(s[s.size() - 2], s[s.size() - 1]) >
                                   intersect(s[s.size() - 1], v[j]))
          s.pop_back();
        s.push_back(v[j]);
      }
    }
    long long cr = 0;
    for (long long j = 1; j <= m; ++j) {
      while (cr < (s.size() - 1) && s[cr].value(j) > s[cr + 1].value(j)) cr++;
      dmin[i][j] = min(dmin[i][j], s[cr].value(j) + i * i + j * j);
    }
  }
  for (long long j = 1; j <= m; ++j) last[j] = 0;
  for (long long i = n; i; --i) {
    vector<func> v;
    vector<func> s;
    for (long long j = m; j; --j) {
      if (a[i][j]) last[j] = i;
      if (last[j]) {
        long long xp = last[j], yp = j;
        func val = {-2 * yp, xp * xp + yp * yp - 2 * xp * i};
        v.push_back(val);
      }
    }
    if (!v.size()) continue;
    reverse(v.begin(), v.end());
    s.push_back(v[0]);
    for (long long j = 1; j < v.size(); ++j) {
      if (v[j].a != v[j - 1].a) {
        while (s.size() > 1 && intersect(s[s.size() - 2], s[s.size() - 1]) >
                                   intersect(s[s.size() - 1], v[j]))
          s.pop_back();
        s.push_back(v[j]);
      }
    }
    long long cr = 0;
    for (long long j = 1; j <= m; ++j) {
      while (cr < (s.size() - 1) && s[cr].value(j) > s[cr + 1].value(j)) cr++;
      dmin[i][j] = min(dmin[i][j], s[cr].value(j) + i * i + j * j);
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) {
      sum += dmin[i][j];
    }
  }
  cout << sum << "\n";
}
