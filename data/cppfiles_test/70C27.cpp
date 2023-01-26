#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 27, p = 1e9 + 7;
int n, q, l, r, d, b, m, c[K][K], rnd;
long long s[N][K], k[N][K], inb[K], ind[K];
bool h;
char ch;
int gtp(int u) { return u < p ? (u < 0 ? u + p : u) : u - p; }
long long ksm(long long x, int y) {
  long long sun = 1;
  while (y) {
    if (y & 1) sun = sun * x % p;
    y >>= 1;
    x = x * x % p;
  }
  return sun;
}
void rd(int &op) {
  op = 0;
  ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    op = (op << 1) + (op << 3) + (ch ^ 48), ch = getchar();
}
void yes() {
  putchar('Y');
  putchar('e');
  putchar('s');
  putchar('\n');
}
void no() {
  putchar('N');
  putchar('o');
  putchar('\n');
}
int main() {
  srand(time(NULL));
  rnd = 0;
  rd(n);
  rd(q);
  k[0][0] = 1;
  for (int i = 1, x; i <= n; i++) {
    rd(x);
    s[i][1] = x + rnd;
    for (int j = 2; j <= 25; j++) s[i][j] = s[i][j - 1] * s[i][1] % p;
    for (int j = 1; j <= 25; j++) s[i][j] = gtp(s[i - 1][j] + s[i][j]);
  }
  for (int i = 1; i <= n; i++) {
    k[i][0] = i + 1;
    k[i][1] = i;
    for (int j = 2; j <= 25; j++) k[i][j] = k[i][j - 1] * k[i][1] % p;
    for (int j = 1; j <= 25; j++) k[i][j] = gtp(k[i - 1][j] + k[i][j]);
  }
  c[0][0] = 1;
  for (int i = 1; i <= 25; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = gtp(c[i - 1][j] + c[i - 1][j - 1]);
  }
  inb[0] = ind[0] = 1;
  for (int i = 1; i <= q; i++) {
    rd(l);
    rd(r);
    rd(d);
    m = r - l + 1;
    h = 1;
    b = ((s[r][1] - s[l - 1][1] - 1ll * m * (m - 1) / 2 % p * d) % p + p) *
        ksm(m, p - 2) % p;
    for (int j = 1; j <= 25; j++) inb[j] = inb[j - 1] * b % p;
    for (int j = 1; j <= 25; j++) ind[j] = ind[j - 1] * d % p;
    for (int j = 2; j <= 25; j++) {
      long long sm = 0;
      for (int o = 0; o <= j; o++)
        sm = (sm + inb[j - o] * ind[o] % p * c[j][o] % p * k[m - 1][o]) % p;
      if (sm != gtp(s[r][j] - s[l - 1][j])) {
        no();
        h = 0;
        break;
      }
    }
    if (h) yes();
  }
}
