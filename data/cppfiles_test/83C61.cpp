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
long long dp[maxn], lcp[5005][5005], n;
void init() {
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = i; j <= n + 1; ++j) {
      lcp[i][j] = 0;
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= i; --j) {
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }
}
bool larger(int x, int y) {
  int num = lcp[y][x];
  return (num != n - x + 1 && s[x + num] > s[y + num]);
}
int main() {
  int TT;
  scanf("%d", &TT);
  for (int TTT = 1; TTT <= TT; TTT++) {
    in(n);
    scanf("%s", s + 1);
    init();
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; ++j) {
        int num = lcp[j][i];
        if (larger(i, j)) dp[i] = max(dp[i], dp[j] + n - i + 1 - num);
      }
      ans = max(ans, dp[i]);
    }
    out(ans, 1);
  }
}
