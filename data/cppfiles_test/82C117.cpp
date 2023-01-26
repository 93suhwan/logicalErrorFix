#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
namespace Output {
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar(' '), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar(' ');
  return;
}
}  // namespace Output
using namespace Output;
long long T;
const long long maxn = 3e5 + 5;
long long n, q;
char s[maxn];
long long sum[maxn];
vector<long long> v[maxn << 2];
long long mx[25][maxn], mn[25][maxn];
long long val(long long i) { return sum[i] + sum[i - 1]; }
void prework() {
  for (long long i = 1; i <= n; i++) mx[0][i] = mn[0][i] = i;
  for (long long j = 1; (1 << j) <= n; j++)
    for (long long i = 1; i + (1 << (j - 1)) - 1 <= n; i++) {
      if (val(mx[j - 1][i]) > val(mx[j - 1][i + (1 << (j - 1))]))
        mx[j][i] = mx[j - 1][i];
      else
        mx[j][i] = mx[j - 1][i + (1 << (j - 1))];
      if (val(mn[j - 1][i]) < val(mn[j - 1][i + (1 << (j - 1))]))
        mn[j][i] = mn[j - 1][i];
      else
        mn[j][i] = mn[j - 1][i + (1 << (j - 1))];
    }
}
long long qmax(long long l, long long r) {
  long long k = log2(r - l + 1);
  if (val(mx[k][l]) > val(mx[k][r - (1 << k) + 1]))
    return mx[k][l];
  else
    return mx[k][r - (1 << k) + 1];
}
long long qmin(long long l, long long r) {
  long long k = log2(r - l + 1);
  if (val(mn[k][l]) > val(mn[k][r - (1 << k) + 1]))
    return mn[k][l];
  else
    return mn[k][r - (1 << k) + 1];
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    q = read();
    scanf("%s", s + 1);
    for (register long long i = 0; i <= 4 * n; ++i) v[i].clear();
    for (register long long i = 1; i <= n; ++i) {
      long long now = 0;
      if (s[i] == '+') {
        if (i & 1)
          sum[i] = sum[i - 1] + 1;
        else
          sum[i] = sum[i - 1] - 1;
      } else {
        if (i & 1)
          sum[i] = sum[i - 1] - 1;
        else
          sum[i] = sum[i - 1] + 1;
      }
    }
    prework();
    for (register long long i = 1; i <= n; ++i)
      v[sum[i] + sum[i - 1] + 2 * n].push_back(i);
    while (q--) {
      long long l = read(), r = read();
      if (sum[r] - sum[l - 1] == 0)
        puts("0");
      else {
        vector<long long>::iterator it =
            lower_bound(v[sum[r] + sum[l - 1] + 2 * n].begin(),
                        v[sum[r] + sum[l - 1] + 2 * n].end(), l);
        if (it != v[sum[r] + sum[l - 1] + 2 * n].end() && *it <= r)
          puts("1"), print(*it), puts("");
        else {
          long long np = qmin(l, r),
                    now = val(np) + sum[l - 1] - sum[r] + 2 * n;
          if (now >= 0 && now <= 4 * n) {
            vector<long long>::iterator it =
                lower_bound(v[now].begin(), v[now].end(), l);
            if (it != v[now].end() && *it < np) {
              puts("2");
              printf("%lld %lld\n", *it, np);
              continue;
            }
          }
          now = val(np) + sum[r] - sum[l - 1] + 2 * n;
          if (now >= 0 && now <= 4 * n) {
            vector<long long>::iterator it =
                lower_bound(v[now].begin(), v[now].end(), np + 1);
            if (it != v[now].end() && *it <= r) {
              puts("2");
              printf("%lld %lld\n", np, *it);
              continue;
            }
          }
          np = qmax(l, r);
          if (now >= 0 && now <= 4 * n) {
            vector<long long>::iterator it =
                lower_bound(v[now].begin(), v[now].end(), l);
            if (it != v[now].end() && *it < np) {
              puts("2");
              printf("%lld %lld\n", *it, np);
              continue;
            }
          }
          now = val(np) + sum[r] - sum[l - 1] + 2 * n;
          if (now >= 0 && now <= 4 * n) {
            vector<long long>::iterator it =
                lower_bound(v[now].begin(), v[now].end(), np + 1);
            if (it != v[now].end() && *it <= r) {
              puts("2");
              printf("%lld %lld\n", np, *it);
            }
          }
        }
      }
    }
  }
  return 0;
}
