#include <bits/stdc++.h>
using namespace std;
const long long N = 201000;
map<long long, long long> mp;
long long cnt = 1;
struct name {
  long long l, r, id;
};
vector<name> vt[2001000];
long long getmp(long long now) {
  if (mp[now]) return mp[now];
  return mp[now] = cnt++;
}
bool tmd(name a, name b) { return a.r < b.r; }
long long x[N];
long long y[N];
long long z[N];
long long ansx[N];
signed main() {
  long long T, n, m, flag, t;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    cnt = 1;
    mp.clear();
    for (long long i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
      t = x[i] + y[i] - z[i];
      t = getmp(t);
      vt[t].push_back(name{max(0ll, x[i] - z[i]), x[i], i});
    }
    long long fans = 0;
    for (long long i = 1; i < cnt; i++) {
      sort(vt[i].begin(), vt[i].end(), tmd);
      long long now = -1;
      for (long long j = 0; j < vt[i].size(); j++) {
        name nt = vt[i][j];
        if (nt.l > now) {
          now = nt.r;
          fans++;
        }
        ansx[nt.id] = now;
      }
    }
    printf("%lld\n", fans);
    for (long long i = 1; i <= n; i++) {
      printf("%lld %lld\n", x[i] - ansx[i],
             y[i] - (x[i] + y[i] - z[i] - ansx[i]));
    }
    for (long long i = 1; i < cnt; i++) {
      vt[i].clear();
    }
  }
  return 0;
}
