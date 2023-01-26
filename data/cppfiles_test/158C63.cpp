#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> x(n);
    for (int i = 0; i < int(n); ++i) scanf("%d", &x[i]);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) scanf("%1d", &a[i][j]);
    int ans = -1;
    vector<int> best;
    for (int mask = 0; mask < int(1 << n); ++mask) {
      vector<int> val(m);
      for (int i = 0; i < int(n); ++i)
        for (int j = 0; j < int(m); ++j)
          if (a[i][j]) val[j] += ((mask >> i) & 1) ? +1 : -1;
      int res = 0;
      for (int i = 0; i < int(n); ++i) res += ((mask >> i) & 1) ? -x[i] : x[i];
      vector<int> p(m);
      iota(p.begin(), p.end(), 0);
      sort(p.begin(), p.end(), [&](int x, int y) { return val[x] < val[y]; });
      for (int i = 0; i < int(m); ++i) res += val[p[i]] * (i + 1);
      if (res > ans) ans = res, best = p;
    }
    vector<int> ansPerm(m);
    for (int i = 0; i < int(m); ++i) ansPerm[best[i]] = i;
    for (int i = 0; i < int(m); ++i) printf("%d ", ansPerm[i] + 1);
    puts("");
  }
}
