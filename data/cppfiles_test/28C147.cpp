#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
long long T, n, m, p[MAXN], f[MAXN], g[MAXN];
map<long long, long long> cnt;
vector<long long> ret;
long long fa[MAXN], vis[MAXN];
int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
}
int main() {
  cin >> T;
  while (T--) {
    ret.clear();
    cin >> n >> m;
    long long val = 0;
    for (long long i = (1); i <= (n); i++) {
      long long tmp;
      cin >> tmp;
      p[tmp] = i;
    }
    for (long long i = (1); i <= (n); i++) {
      if (i != p[i]) val++;
    }
    f[0] = g[0] = f[n + 1] = g[n + 1] = 0;
    cnt.clear();
    for (long long i = (1); i <= (n); i++) {
      cnt[p[i] - i]++;
      f[i] = i - cnt[n - i];
    }
    cnt.clear();
    for (long long i = (n); i >= (1); i--) {
      cnt[i - p[i]]++;
      g[i] = (n - i + 1) - cnt[i - 1];
    }
    for (long long i = (1); i <= (n); i++) {
      if ((n - f[i] - g[i + 1]) < (n / 3)) continue;
      for (long long j = (1); j <= (n); j++) fa[j] = j, vis[j] = 0;
      for (long long j = (1); j <= (n); j++) {
        if (j <= i) {
          fa[Find(j + n - i)] = Find(p[j]);
        } else {
          fa[Find(j - i)] = Find(p[j]);
        }
      }
      long long num = 0;
      for (long long j = (1); j <= (n); j++) {
        if (vis[Find(j)]) continue;
        vis[Find(j)] = 1;
        num++;
      }
      if (n - num <= m) ret.push_back(n - i);
    }
    sort(ret.begin(), ret.end());
    long long sz = ret.size();
    printf("%lld ", sz);
    for (long long j = (0); j <= (sz - 1); j++) printf("%lld ", ret[j]);
    printf("\n");
  }
  return 0;
}
