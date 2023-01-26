#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * w;
}
inline void print(long long x, long long op = 10) {
  if (!x) {
    putchar('0');
    if (op) putchar(op);
    return;
  }
  char F[40];
  long long tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  long long cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
  if (op) putchar(op);
}
const long long N = 3e5 + 7;
char s[N];
long long sum[N];
long long solve() {
  long long n = read(), Q = read();
  scanf("%s", s + 1);
  sum[0] = 0;
  for (long long i = 1; i <= n; ++i) {
    long long now = s[i] == '+' ? 1 : -1;
    if (!(i & 1)) now = -now;
    sum[i] = sum[i - 1] + now;
  }
  vector<vector<long long>> p(4 * n + 1);
  for (long long i = 1; i <= n; ++i) {
    p[sum[i] + sum[i - 1] + 2 * n].push_back(i);
  }
  while (Q--) {
    long long l = read(), r = read();
    if (sum[r] - sum[l - 1] == 0) {
      print(0);
      continue;
    }
    vector<long long> res;
    if ((r - l + 1) % 2 == 0) {
      res.push_back(r);
      --r;
    }
    long long x = sum[r] + sum[l - 1] + 2 * n;
    long long pos = *lower_bound(p[x].begin(), p[x].end(), l);
    res.push_back(pos);
    print(res.size());
    for (auto& it : res) {
      print(it, 32);
    }
    puts("");
  }
  return 1;
}
signed main() {
  long long T = read();
  for (long long i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
