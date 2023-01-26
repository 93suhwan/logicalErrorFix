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
  pair<long double, pair<pair<int, int>, pair<int, int> > > near;
  near.first = 1e18;
  for (int i = 0; i < ano.size() - 1; ++i)
    near = min(near, make_pair(dist(a[p], ano[i]) + dist(a[p], ano[i + 1]),
                               make_pair(ano[i], ano[i + 1])));
  vector<pair<int, int> > Tmp;
  Tmp.push_back(ano[0]);
  Tmp.push_back(ano.back());
  Tmp.push_back(a[p]);
  for (int i = 0; i < ano.size(); ++i) {
    if (i && ano[i - 1] == a[k])
      Tmp.push_back(ano[i]);
    else if (i != ano.size() - 1 && ano[i + 1] == a[k])
      Tmp.push_back(ano[i]);
  }
  sort(Tmp.begin(), Tmp.end());
  long double ans = 1e18;
  do {
    long double temp = dist(a[k], Tmp[0]);
    for (int i = 0; i < Tmp.size(); ++i) {
      if (i) temp += dist(Tmp[i], Tmp[i - 1]);
    }
    ans = min(ans, temp);
  } while (next_permutation(Tmp.begin(), Tmp.end()));
  printf("%.10Lf\n", ans);
  return 0;
}
