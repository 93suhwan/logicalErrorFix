#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
template <typename T>
inline void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
  return;
}
const int MOD = 1e9 + 7;
inline int inc(int x, int y) {
  x += y;
  return x >= MOD ? x - MOD : x;
}
inline int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + MOD : x;
}
inline void incc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void decc(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline void chkmin(int &x, int y) {
  if (y < x) x = y;
}
inline void chkmax(int &x, int y) {
  if (y > x) x = y;
}
const int N = 2e5 + 5, M = 3005, INF = 1e9 + 7;
namespace Map {
const int Size = 1e6 + 5;
int head[Size], nex[Size], val[Size], idx, sta[Size], top;
int to[Size];
const int mod = 999983;
inline void Reset() {
  for (int i = 1; i <= top; i++) head[sta[i]] = 0;
  idx = 0;
  return;
}
inline void Insert(int x, int v) {
  int key = (x % mod * 131) % mod * 13 % mod;
  for (int i = head[key]; i; i = nex[i])
    if (to[i] == x) return val[i] += v, void();
  nex[++idx] = head[key], to[idx] = x, val[idx] = v, head[key] = idx;
  sta[++top] = key;
  return;
}
inline int Count(int x) {
  int key = (x % mod * 131) % mod * 13 % mod;
  for (int i = head[key]; i; i = nex[i])
    if (to[i] == x) return val[i];
  return 0;
}
}  // namespace Map
int n, m, a[N];
signed main() {
  int t;
  read(t);
  while (t--) {
    read(n);
    Map::Reset();
    double sum = 0;
    for (register int i = (1); i <= (n); i++)
      read(a[i]), Map::Insert(a[i], 1), sum += (double)a[i];
    sum = sum * 1.0 / (n * 1.0);
    sum *= 2.0;
    if (floor(sum) != sum)
      puts("0");
    else {
      int tmp = sum;
      long long Ans = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] + a[i] < tmp) Ans += Map::Count(tmp - a[i]);
      }
      if (!(tmp & 1)) {
        int tp = Map::Count(tmp / 2);
        Ans += 1ll * tp * (tp - 1) / 2;
      }
      write(Ans), putchar('\n');
    }
  }
  return 0;
}
