#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const long long N = 300010;
struct edge {
  long long v, w, nx;
} e[N << 1];
long long hd[N], cnt;
void add(long long u, long long v, long long w) {
  e[++cnt] = (edge){v, w, hd[u]};
  hd[u] = cnt;
}
long long qp(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
long long t, n, m, ans;
const long long mod = 998244353;
char c[100010][2];
bool is(char c1, char c2, char c3, char c4) {
  if (c1 == '?')
    ;
  else if (c1 != c3)
    return 0;
  if (c2 == '?')
    ;
  else if (c2 != c4)
    return 0;
  return 1;
}
long long dpp[100010];
long long b, w;
long long C(long long n, long long m) {
  long long ans = 1;
  for (long long i = n - m + 1; i <= n; i++) ans = ans * i % mod;
  for (long long i = 1; i <= m; i++) ans = ans * qp(i, mod - 2, mod) % mod;
  return ans;
}
int main() {
  n = rd();
  for (long long i = 1; i <= n; i++)
    cin >> c[i][0] >> c[i][1], b += (c[i][0] == 'B') + (c[i][1] == 'B'),
        w += (c[i][0] == 'W') + (c[i][1] == 'W');
  ans = 2;
  for (long long i = 1; i <= n; i++)
    if (!is(c[i][0], c[i][1], 'B', 'W')) {
      ans--;
      break;
    }
  for (long long i = 1; i <= n; i++)
    if (!is(c[i][0], c[i][1], 'W', 'B')) {
      ans--;
      break;
    }
  dpp[0] = 1;
  for (long long i = 1; i <= n; i++) {
    if (is(c[i][0], c[i][1], 'B', 'W')) dpp[i] += dpp[i - 1];
    if (is(c[i][0], c[i][1], 'W', 'B')) dpp[i] += dpp[i - 1];
    dpp[i] %= mod;
  }
  if (b > n || w > n) {
    puts("0");
    return 0;
  }
  printf("%d\n", (ans + C(2 * n - b - w, n - b) - dpp[n] + mod) % mod);
  return 0;
}
