#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
double start = clock();
const double TL = 4.2;
const double Start = 1000;
const double Change = 0.999;
const double eps = 1e-6;
long long n, m, k, mxdeg[52], deg[52], dist[52][52], st[52][52], fa[52];
long long getf(long long x) { return x == fa[x] ? x : fa[x] = getf(fa[x]); }
struct simulateAnneal {
  long long curans, mnans;
  void init() {
    curans = 1000000000000000000;
    mnans = 1000000000000000000;
    return;
  }
  pair<long long, long long> get_change() {
    long long x, y;
    x = y = -1;
    while (x == y) {
      x = rnd() % n;
      y = rnd() % n;
    }
    st[x][y] ^= 1;
    st[y][x] ^= 1;
    return make_pair(x, y);
  }
  void rem_change(long long x, long long y) {
    st[x][y] ^= 1;
    st[y][x] ^= 1;
    return;
  }
  long long calc_val() {
    long long i, j, ret = 0;
    vector<pair<long long, pair<long long, long long> > > req;
    for (i = 0; i < n; i++) {
      deg[i] = 0;
      fa[i] = i;
    }
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (st[i][j]) {
          if (getf(i) == getf(j)) {
            return 1000000000000000000;
          }
          ret += dist[i][j];
          deg[i]++;
          deg[j]++;
          fa[getf(i)] = getf(j);
        } else {
          req.push_back(make_pair(dist[i][j], make_pair(i, j)));
        }
      }
    }
    for (i = 0; i < k; i++) {
      if (deg[i] > mxdeg[i]) {
        return 1000000000000000000;
      }
    }
    sort(req.begin(), req.end());
    for (i = 0; i < req.size(); i++) {
      long long x = req[i].second.first, y = req[i].second.second;
      if (getf(x) == getf(y)) {
        continue;
      }
      if (x < k && deg[x] >= mxdeg[x]) {
        continue;
      }
      if (y < k && deg[y] >= mxdeg[y]) {
        continue;
      }
      deg[x]++;
      deg[y]++;
      fa[getf(x)] = getf(y);
      ret += req[i].first;
    }
    long long cnt = 0;
    for (i = 0; i < n; i++) {
      if (getf(i) == i) {
        cnt++;
      }
    }
    if (cnt <= 1) {
      return ret;
    }
    return 1000000000000000000;
  }
  void solve() {
    double T;
    for (T = Start; T > eps; T *= Change) {
      pair<long long, long long> modify = get_change();
      long long nval = calc_val();
      long long delta = curans - nval;
      if (exp((double)delta / T) >
          (double)(rnd() % 1000000000) / (double)1000000000.0) {
        curans = nval;
        mnans = min(mnans, curans);
      } else {
        rem_change(modify.first, modify.second);
      }
    }
    return;
  }
} sa;
int main() {
  long long i, j;
  scanf("%lld%lld", &n, &k);
  for (i = 0; i < k; i++) {
    scanf("%lld", &mxdeg[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      scanf("%lld", &dist[i][j]);
      dist[j][i] = dist[i][j];
    }
  }
  memset(st, 0, sizeof(st));
  sa.init();
  while (clock() < start + CLOCKS_PER_SEC * TL) {
    sa.solve();
  }
  printf("%lld\n", sa.mnans);
  return 0;
}
