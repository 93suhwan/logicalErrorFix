#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand() { return rng() & 0X7FFFFFFF; }
const int N = 55;
int n, K, d[N], w[N];
struct edge {
  int u, v, w, w_;
  bool operator<(const edge& k) const { return w_ < k.w_; }
};
vector<edge> es;
int d_[N];
struct ufs {
  int fa[N];
  void init() {
    for (int i = (1); i <= (n); ++i) fa[i] = i;
  }
  int fd(int k1) { return fa[k1] == k1 ? k1 : fa[k1] = fd(fa[k1]); }
  int mer(int k1, int k2) {
    k1 = fd(k1), k2 = fd(k2);
    if (k1 == k2) return 0;
    fa[k1] = k2;
    return 1;
  }
} o;
int main() {
  scanf("%d%d", &n, &K);
  for (int i = (1); i <= (K); ++i) scanf("%d", &d[i]);
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j) {
      int x;
      scanf("%d", &x);
      es.push_back((edge){i, j, x, x});
    }
  sort(es.begin(), es.end());
  bool fir = 1;
  int ans = 0X3F3F3F3F;
  int tt = 0;
  while (1) {
    if (((++tt) & 255) == 0 && clock() > 5.5 * CLOCKS_PER_SEC) {
      break;
    }
    if (fir)
      fir = 0;
    else {
      for (int i = (1); i <= (K); ++i) {
        w[i] = brand() % 200 - 100;
      }
    }
    for (auto& x : es) {
      x.w_ = x.w;
      if (x.u <= n) x.w_ -= w[x.u];
      if (x.v <= n) x.w_ -= w[x.v];
    }
    sort(es.begin(), es.end());
    o.init();
    for (int i = (1); i <= (n); ++i) d_[i] = 0;
    int cnt = 0, sum = 0;
    for (auto& x : es) {
      if (o.mer(x.u, x.v)) {
        ++cnt;
        sum += x.w;
        ++d_[x.u], ++d_[x.v];
        if (cnt == n - 1) break;
      }
    }
    bool err = 0;
    for (int i = (1); i <= (K); ++i)
      if (d_[i] > d[i]) err = 1;
    if (!err) ans = min(ans, sum);
  }
  printf("%d\n", ans);
  return 0;
}
