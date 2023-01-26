#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int mod = 998244353;
long long pw2[MAXN];
struct Data {
  int n, m;
  int cnt[MAXN][2], cnt_bad = 0;
  map<int, int> a[MAXN];
  int t[MAXN], tot = 0;
  inline int get_bad(int x) { return !cnt[x][0] || !cnt[x][1]; }
  inline void update(int x, int y, int k) {
    cnt_bad -= get_bad(x);
    if (a[x].find(y) != a[x].end()) {
      --cnt[x][a[x][y] ^ (y & 1)];
      a[x].erase(y);
      if (!--t[x]) --tot;
    }
    if (k != -1) {
      ++cnt[x][k ^ (y & 1)];
      a[x][y] = k;
      if (!t[x]++) ++tot;
    }
    cnt_bad += get_bad(x);
  }
  inline long long calc(void) { return cnt_bad ? 0 : pw2[n - tot]; }
} p, q;
int main(void) {
  pw2[0] = 1;
  for (int i = 1; i < MAXN; ++i) pw2[i] = pw2[i - 1] * 2 % mod;
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  p.n = n;
  p.m = m;
  q.n = m;
  q.m = n;
  while (Q--) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    p.update(x, y, k);
    q.update(y, x, k);
    long long ans = (p.calc() + q.calc()) % mod;
    if (!p.cnt_bad && !q.cnt_bad) --ans;
    if (!p.tot && !q.tot) --ans;
    ans = (ans + mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
