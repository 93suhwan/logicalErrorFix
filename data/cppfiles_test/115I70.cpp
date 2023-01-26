#include <bits/stdc++.h>
using namespace std;
long long get() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long N = 1e6 + 5, P = 998244353;
long long n, m, q, pw2[N];
long long cnt[2];
map<long long, long long> col[N];
struct State {
  long long cnt[N][2], fck, det;
  void add(long long x, long long y, long long col) {
    fck -= cnt[x][0] && cnt[x][1];
    det -= cnt[x][0] || cnt[x][1];
    ++cnt[x][(y & 1) ^ col];
    fck += cnt[x][0] && cnt[x][1];
    det += cnt[x][0] || cnt[x][1];
  }
  void del(long long x, long long y, long long col) {
    fck -= cnt[x][0] && cnt[x][1];
    det -= cnt[x][0] || cnt[x][1];
    --cnt[x][(y & 1) ^ col];
    fck += cnt[x][0] && cnt[x][1];
    det += cnt[x][0] || cnt[x][1];
  }
  long long ask() {
    if (fck)
      return 0;
    else
      return pw2[n - det];
  }
} R, C;
void add(long long x, long long y, long long c) {
  if (col[x][y])
    R.del(x, y, col[x][y] - 1), C.del(y, x, col[x][y] - 1),
        cnt[((x + y) & 1) ^ (col[x][y] - 1)]--;
  col[x][y] = c + 1;
  R.add(x, y, col[x][y] - 1), C.add(y, x, col[x][y] - 1);
  cnt[((x + y) & 1) ^ c]++;
}
void del(long long x, long long y) {
  if (col[x][y])
    R.del(x, y, col[x][y] - 1), C.del(y, x, col[x][y] - 1),
        cnt[((x + y) & 1) ^ (col[x][y] - 1)]--;
  col[x][y] = 0;
}
long long ask() {
  long long res = R.ask() + C.ask();
  if (!cnt[0]) --res;
  if (!cnt[1]) --res;
  return (res + P) % P;
}
signed main() {
  n = get(), m = get(), q = get();
  pw2[0] = 1;
  for (long long i = 1; i <= max(n, m); i++) pw2[i] = pw2[i - 1] * 2 % P;
  for (long long i = 1; i <= q; i++) {
    long long x = get(), y = get(), t = get();
    if (t == -1)
      del(x, y);
    else
      add(x, y, t);
    printf("%lld\n", ask());
  }
  return 0;
}
