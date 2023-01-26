#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 20;
long long prime[M];
int n, m, z[N * 2];
void Z(string s) {
  int len = s.size(), l = 0, r = 0;
  z[0] = len;
  for (int i = 1; i < len; i++) {
    if (l + r > i) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < len && s[z[i]] == s[i + z[i]]) z[i]++;
    if (z[i] + i > l + r) l = i, r = z[i];
  }
  return;
}
string st;
long long pw;
char s[N], t[N];
struct H {
  long long mod, h[N], p[N];
  long long val;
  void init() {
    p[0] = 1;
    for (int i = 1; i <= 5e5; i++) p[i] = p[i - 1] * pw % mod;
    for (int i = 0; i < n; i++) {
      if (i) h[i] = h[i - 1] * pw % mod;
      h[i] = h[i] + s[i] - '0';
      h[i] %= mod;
    }
    for (int i = 0; i < m; i++) val = (val * pw % mod + t[i] - '0') % mod;
    return;
  }
  long long gh(int l, int r) {
    return (h[r] - (l == 0 ? 0 : h[l - 1]) * p[r - l + 1] % mod + mod) % mod;
  }
} f[22];
long long random(long long mod) {
  long long res = rand();
  for (int i = 0; i < 5; i++) res = res * rand() % mod;
  res += rand();
  res %= mod;
  return res;
}
bool check(long long p) {
  for (long long i = 2; i * i <= p; i++)
    if (p % i == 0) return false;
  return true;
}
long long getprime() {
  while (1) {
    long long res = 1e9 + random(1e9);
    if (check(res)) return res;
  }
}
bool judge(int l, int r, int L, int R) {
  for (int i = 0; i < 1; i++) {
    long long v = f[i].gh(l, r);
    long long V = f[i].gh(L, R);
    v = (v + V) % f[i].mod;
    if (v != f[i].val) return false;
  }
  return true;
}
int main() {
  srand(time(0));
  pw = 10;
  prime[0] = 1000000007;
  prime[1] = 1000000009;
  prime[2] = 1000000021;
  prime[3] = 1004535809;
  prime[4] = 1000010801;
  scanf("%s", &s);
  scanf("%s", &t);
  n = strlen(s), m = strlen(t);
  for (int i = 0; i < m; i++) st += t[i];
  for (int i = 0; i < n; i++) st += s[i];
  Z(st);
  for (int i = 5; i < M; i++) prime[i] = getprime();
  for (int i = 0; i < M; i++) f[i].mod = prime[i], f[i].init();
  for (int i = 0; i + m <= n; i++) {
    int j = z[i + m];
    if (j < m && judge(i, i + m - 1, i + m, i + m * 2 - j - 1)) {
      printf("%d %d\n%d %d\n", i + 1, i + m, i + m + 1, i + m * 2 - j);
      return 0;
    }
    if (j < m && i - (m - j) >= 0 && judge(i - (m - j), i - 1, i, i + m - 1)) {
      printf("%d %d\n%d %d\n", i - (m - j) + 1, i, i + 1, i + m);
      return 0;
    }
    if (judge(i, i + m - 1, i + m, i + m * 2 - j - 2)) {
      printf("%d %d\n%d %d\n", i + 1, i + m, i + m + 1, i + m * 2 - j - 1);
      return 0;
    }
    if (i - m + 1 >= 0 && judge(i - m + 1, i - 1, i, i + m - 1)) {
      printf("%d %d\n%d %d\n", i - m + 2, i, i + 1, i + m);
      return 0;
    }
  }
  return 0;
}
