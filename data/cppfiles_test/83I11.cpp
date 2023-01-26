#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
int in(int &a, int &b, int &c, int &d) {
  return scanf("%d%d%d%d", &a, &b, &c, &d);
}
int in(int &a, int &b, int &c) { return scanf("%d%d%d", &a, &b, &c); }
int in(int &a, int &b) { return scanf("%d%d", &a, &b); }
int in(long long &a, long long &b) { return scanf("%lld%lld", &a, &b); }
int in(long long &a, long long &b, long long &c, long long &d) {
  return scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
}
int in(long long &a, long long &b, long long &c) {
  return scanf("%lld%lld%lld", &a, &b, &c);
}
int in(long long &a) { return scanf("%lld", &a); }
int in(int &a) { return scanf("%d", &a); }
int in(char *s) { return scanf("%s", s); }
int in(char &c) { return scanf("%c", &c); }
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
char s[maxn];
int x[maxn], y[maxn], c[maxn], sa[maxn], rk[maxn], height[maxn];
long long dp[maxn];
int n, m, st[maxn][20];
void get_SA() {
  n = strlen(s + 1);
  m = 122;
  memset((c), (0), sizeof(c));
  for (int i = 1; i <= n; ++i) c[x[i] = s[i]]++;
  for (int i = 2; i <= m; ++i) c[i] += c[i - 1];
  for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) c[x[i]]++;
    for (int i = 2; i <= m; ++i) c[i] += c[i - 1];
    for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
    swap(x, y);
    x[sa[1]] = 1, num = 1;
    for (int i = 2; i <= n; ++i)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? num
                     : ++num;
    if (num == n) break;
    m = num;
  }
}
void get_height() {
  int k = 0;
  for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
  for (int i = 1; i <= n; ++i) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}
void build_st() {
  for (int i = 1; i <= n; ++i) st[i][0] = height[i];
  for (int j = 1; j <= 19; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int lcp(int x, int y) {
  int l = rk[x], r = rk[y];
  if (l > r) swap(l, r);
  if (l == r) return n - x + 1;
  l++;
  int t = log2(r - l + 1);
  return min(st[l][t], st[r - (1 << t) + 1][t]);
}
int main() {
  int TT;
  scanf("%d", &TT);
  for (int TTT = 1; TTT <= TT; TTT++) {
    in(n);
    scanf("%s", s + 1);
    get_SA();
    get_height();
    build_st();
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; ++j) {
        int num = lcp(i, j);
        if (i + num == n + 1) continue;
        if (j + num != n + 1 && s[i + num] < s[j + num]) continue;
        dp[i] = max(dp[i], dp[j] + n - i + 1 - num);
      }
      ans = max(ans, dp[i]);
    }
    out(ans, 1);
  }
}
