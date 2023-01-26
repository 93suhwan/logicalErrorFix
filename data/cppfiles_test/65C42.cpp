#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long INF = (long long)2e18;
const int MOD = 998244353;
int _abs(int x) { return x < 0 ? -x : x; }
int add(int x, int y) {
  x += y;
  return x >= MOD ? x - MOD : x;
}
int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + MOD : x;
}
void Add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void Sub(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
void Mul(int &x, int y) { x = (long long)(x) * (y) % MOD; }
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)(ret) * (x) % MOD;
    x = (long long)(x) * (x) % MOD;
    y >>= 1;
  }
  return ret;
}
void checkmin(int &x, int y) {
  if (x > y) x = y;
}
void checkmax(int &x, int y) {
  if (x < y) x = y;
}
void checkmin(long long &x, long long y) {
  if (x > y) x = y;
}
void checkmax(long long &x, long long y) {
  if (x < y) x = y;
}
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
const long long N = 200005;
long long n, a[N];
char s[N];
long long w[N], op[N];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++)
    if (s[i] == 'L')
      op[i] = -1;
    else
      op[i] = 1;
  w[n] = op[n];
  for (long long i = n - 1; i; i--) w[i] = -w[i + 1];
  vector<long long> g;
  long long l = 1, r = n;
  for (long long i = n - 1; i; i--) {
    if (w[r] * op[i] > 0)
      g.push_back(l), l++;
    else
      g.push_back(r), r--;
  }
  g.push_back(l);
  reverse(g.begin(), g.end());
  long long now = 1, suml = 0, sumr = 0;
  for (auto &i : g) {
    if (w[i] == -1)
      suml += a[i];
    else
      sumr += a[i];
    if (suml == sumr || (suml < sumr && op[now] == -1) ||
        (sumr < suml && op[now] == 1)) {
      puts("-1");
      return 0;
    }
    now++;
  }
  for (auto &i : g) {
    if (w[i] == -1)
      printf("%d L\n", a[i]);
    else
      printf("%d R\n", a[i]);
  }
  return 0;
}
