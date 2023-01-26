#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 1e9 + 10;
const int N = 2e5 + 10;
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x;
}
inline int add(int x, int y) {
  x += y;
  (x >= mod && (x -= mod));
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  (x < 0 && (x += mod));
  return x;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y, int p = mod) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int dp[N], n;
pair<int, int> rnk[N];
int rid[N];
int need[N], s;
set<int, greater<int> > remain;
int lb(int x) { return x & (-x); }
int b[N << 1];
void mdy(int p, int v) {
  while (p <= (n << 1)) {
    b[p] = add(b[p], v);
    p += lb(p);
  }
}
int qry(int p) {
  int x = 0;
  while (p) {
    x = add(x, b[p]);
    p -= lb(p);
  }
  return x;
}
int qry(int r, int l) { return sub(qry(r), qry(l - 1)); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &rnk[i].first, &rnk[i].second);
    rid[i] = i;
  }
  scanf("%d", &s);
  for (int i = 1; i <= s; i++) scanf("%d", &need[i]);
  sort(rid + 1, rid + 1 + n,
       [](int x, int y) -> bool { return rnk[x] < rnk[y]; });
  dp[n] = 1;
  mdy(rnk[rid[n]].second, 1);
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = add(1, qry(rnk[rid[i]].second));
    mdy(rnk[rid[i]].second, dp[i]);
  }
  for (int i = 1; i <= s; i++) remain.insert(rnk[need[i]].second);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (rnk[rid[i]].second <= *remain.begin()) {
      ans = add(ans, dp[i]);
    }
    remain.erase(rnk[rid[i]].second);
  }
  cout << ans;
  return 0;
}
