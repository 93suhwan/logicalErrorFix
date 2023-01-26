#include <bits/stdc++.h>
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n, K;
struct pt {
  long long x, y;
  pt(long long X = 0, long long Y = 0) { x = X, y = Y; }
  const pt operator+(const pt &a) const { return pt(x + a.x, y + a.y); }
  const pt operator-(const pt &a) const { return pt(x - a.x, y - a.y); }
} a[422];
int nxt[422], pre[422];
long long Dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
long long Cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
int dp[422][422];
pair<int, int> pos[422][422];
int check(long long w) {
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (0); j <= (n - 1); j++)
      dp[i][j] = -1e7, pos[i][j] = make_pair(-1, -1);
  for (int len = (2); len <= (n - 1); len++)
    for (int i = (0); i <= (n - 1); i++) {
      int j = (i + len) % n;
      long long sum = 0;
      for (int k = nxt[i]; k != j; k = nxt[k])
        sum += abs(Cross(a[k] - a[pre[k]], a[k] - a[j]));
      if (sum < w) continue;
      dp[i][j] = 1;
      for (int k = nxt[i]; k != j; k = nxt[k])
        if (abs(Cross(a[k] - a[i], a[k] - a[j])) >= w &&
            chkmax(dp[i][j], 1 + dp[i][k] + dp[k][j]))
          pos[i][j] = make_pair(k, k);
      int l = i, r = j;
      long long cur = 0;
      while (cur < w)
        r = pre[r], cur += abs(Cross(a[r] - a[l], a[r] - a[nxt[r]]));
      chkmax(dp[i][j], dp[l][r] + 1);
      while (l != pre[j]) {
        l = nxt[l];
        if (pre[l] != r)
          cur += abs(Cross(a[l] - a[pre[l]], a[l] - a[r]));
        else
          r = l, cur = sum;
        while (r != j && cur - abs(Cross(a[r] - a[l], a[r] - a[nxt[r]])) >= w)
          cur -= abs(Cross(a[r] - a[l], a[r] - a[nxt[r]])), r = nxt[r];
        if (chkmax(dp[i][j], 1 + dp[l][r])) pos[i][j] = make_pair(l, r);
      }
    }
  int mx = 0;
  for (int l = (0); l <= (n - 1); l++)
    for (int r = (l + 2); r <= (n - 1); r++)
      chkmax(mx, dp[l][r] + dp[r][l] - 1);
  return mx;
}
int main() {
  file();
  read(n, K);
  for (int i = (0); i <= (n - 1); i++)
    read(a[i].x, a[i].y), pre[i] = (i - 1 + n) % n, nxt[i] = (i + 1) % n;
  if (K == 0) {
    long long s = 0;
    for (int i = (1); i <= (n - 2); i++)
      s += abs(Cross(a[i] - a[i - 1], a[i] - a[n - 1]));
    cout << s;
    return 0;
  }
  long long l = 0, r = 1e18, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid) >= K)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans;
  return 0;
}
