#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXBITS = 19;
const int MAXN = 1 << MAXBITS;
struct Res {
  int mn, mx, best;
  Res() {}
  Res(int mn, int mx, int best) : mn(mn), mx(mx), best(best) {}
};
int n, nbits;
int a[MAXN];
int ans[1 << MAXBITS];
int cnt[1 << MAXBITS];
Res combine(const Res& a, const Res& b, int step) {
  Res ret;
  ret.mn = a.mn != INT_MAX ? a.mn : b.mn != INT_MAX ? step + b.mn : INT_MAX;
  ret.mx = b.mx != INT_MIN ? step + b.mx : a.mx != INT_MIN ? a.mx : INT_MIN;
  ret.best = min(a.best, b.best);
  if (a.mx != INT_MIN && b.mn != INT_MAX)
    ret.best = min(ret.best, step + b.mn - a.mx);
  return ret;
}
vector<Res> rec(int offset, int k) {
  vector<Res> ret(1 << k);
  if (k == 0) {
    if (cnt[offset] == 0)
      ret[0] = Res(INT_MAX, INT_MIN, INT_MAX);
    else
      ret[0] = Res(0, 0, INT_MAX);
  } else {
    vector<Res> l = rec(offset, k - 1);
    vector<Res> r = rec(offset + (1 << (k - 1)), k - 1);
    for (int i = (0); i < (1 << (k - 1)); ++i) {
      ret[i] = combine(l[i], r[i], 1 << (k - 1));
      ret[(1 << (k - 1)) + i] = combine(r[i], l[i], 1 << (k - 1));
    }
  }
  return ret;
}
void solve() {
  for (int i = (0); i < (1 << nbits); ++i) cnt[i] = 0;
  for (int i = (0); i < (n); ++i) ++cnt[a[i]];
  for (int i = (0); i < (1 << nbits); ++i)
    if (cnt[i] >= 2) {
      for (int j = (0); j < (1 << nbits); ++j) ans[i] = 0;
      return;
    }
  vector<Res> res = rec(0, nbits);
  for (int i = (0); i < (1 << nbits); ++i) ans[i] = res[i].best;
}
void run() {
  scanf("%d%d", &n, &nbits);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  solve();
  for (int i = (0); i < (1 << nbits); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
