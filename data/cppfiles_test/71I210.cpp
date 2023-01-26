#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int n, k;
int p = 0;
pair<int, int> a[MAXN];
long double dist(pair<int, int> A, pair<int, int> B) {
  long double d1, d2;
  d1 = A.first - B.first;
  d2 = A.second - B.second;
  return sqrt(d1 * d1 + d2 * d2);
}
long double solvetor(vector<pair<int, int> > x) {
  long double tmp = dist(x[0], x.back());
  tmp += dist(x.back(), a[p]);
  for (int i = 0; i < x.size() - 1; ++i)
    tmp = min(tmp, dist(x[i], x[0]) + dist(x[i + 1], x.back()) +
                       dist(x[i], a[p]) + dist(a[p], x[i + 1]));
  return tmp;
}
long double solvetol(vector<pair<int, int> > x) {
  long double tmp = dist(x[0], x.back());
  tmp += dist(x[0], a[p]);
  for (int i = 0; i < x.size() - 1; ++i)
    tmp = min(tmp, dist(x[i], x[0]) + dist(x[i + 1], x.back()) +
                       dist(x[i], a[p]) + dist(a[p], x[i + 1]));
  return tmp;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (true) {
    int x, y;
    x = rng() % n + 1;
    y = rng() % n + 1;
    if (x != y) {
      vector<int> tmp;
      for (int i = 1; i <= n; ++i)
        if (i != y && i != x) {
          if (1ll * (a[i].second - a[y].second) * (a[i].first - a[x].first) ==
              1ll * (a[i].second - a[x].second) * (a[i].first - a[y].first))
            ;
          else
            tmp.push_back(i);
        }
      if (tmp.size() == 1) {
        p = tmp[0];
        break;
      }
    }
  }
  vector<pair<int, int> > ano;
  for (int i = 1; i <= n; ++i)
    if (i != p) ano.push_back(a[i]);
  sort(ano.begin(), ano.end());
  if (k == p) {
    long double ans = 1e18;
    long double dis = dist(ano[0], ano.back());
    for (int i = 1; i <= n; ++i)
      if (i != p)
        ans = min(ans, dis + dist(a[i], a[p]) +
                           min(dist(a[i], ano[0]), dist(a[i], ano.back())));
    printf("%.10Lf\n", ans);
  } else {
    long double ans = 1e18;
    if (a[k] == ano[0]) {
      ans = min(ans, solvetor(ano));
    } else if (a[k] == ano.back()) {
      ans = min(ans, solvetol(ano));
    } else {
      ano.clear();
      for (int i = 1; i <= n; ++i)
        if (i != p && i != k) ano.push_back(a[i]);
      sort(ano.begin(), ano.end());
      ans = min(ans, solvetor(ano) + dist(a[k], ano[0]));
      ans = min(ans, solvetol(ano) + dist(a[k], ano.back()));
    }
    ano.clear();
    for (int i = 1; i <= n; ++i)
      if (i != p && i != k) ano.push_back(a[i]);
    sort(ano.begin(), ano.end());
    ans = min(ans, dist(a[k], a[p]) + dist(ano[0], ano.back()) +
                       min(dist(a[p], ano[0]), dist(a[p], ano.back())));
    printf("%.10Lf\n", ans);
  }
  return 0;
}
