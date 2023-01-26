#include <bits/stdc++.h>
namespace nb {
template <typename A, typename B>
inline void swap(A &a, B &b) {
  a ^= b ^= a ^= b;
}
template <typename A, typename B>
inline A max(const A &a, const B &b) {
  return a > b ? a : b;
}
template <typename A, typename B>
inline A min(const A &a, const B &b) {
  return a < b ? a : b;
}
template <typename A, typename B>
inline void Max(A &a, const B &b) {
  a = (a > b ? a : b);
}
template <typename A, typename B>
inline void Min(A &a, const B &b) {
  a = (a < b ? a : b);
}
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pli = pair<ll, int>;
using vi = vector<int>;
using vl = vector<ll>;
using qi = queue<int>;
using dijq = priority_queue<pi, vector<pi>, greater<pi> >;
using dijl = priority_queue<pli, vector<pli>, greater<pli> >;
template <typename A>
inline A lowbit(A a) {
  return a & -a;
}
inline int read() {
  int s = 0, w = 1;
  char ch;
  while ((ch = getchar()) > '9' || ch < '0')
    if (ch == '-') w = -1;
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
inline ll lread() {
  long long s = 0, w = 1;
  char ch;
  while ((ch = getchar()) > '9' || ch < '0')
    if (ch == '-') w = -1;
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
inline void read(int &n, int *a, int flag = 0) {
  if (flag) n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
}
template <typename A>
void write(A s, char ch = 0) {
  if (s < 0) {
    s = -s;
    putchar('-');
  }
  if (s > 9) write(s / 10, 0);
  putchar(s - s / 10 * 10 + '0');
  if (ch) putchar(ch);
}
template <typename A>
inline void write(int n, A *a, char ch, bool flag = 0) {
  for (int i = (1); i <= (n); ++i) write(a[i], ch);
  if (!flag) putchar('\n');
}
inline int gcd(int a, int b) {
  int r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
}  // namespace nb
using namespace nb;
char in[21][400002];
int ma[21][400002];
int dp[1048576];
int num[20];
int l[20];
int r[20];
int n;
signed main() {
  int t = 1;
  while (t--) {
    n = lread();
    for (int i = 0; i < n; i++) scanf("%s", in[i] + 1);
    for (int i = 0; i < n; i++) {
      int p = 0;
      int pp = 0;
      for (int j = 1; in[i][j]; j++) {
        if (in[i][j] == '(')
          l[i]++, p--;
        else
          r[i]++, num[i] = max(num[i], r[i] - l[i]), p++;
        pp = max(pp, p);
        if (r[i] - l[i] >= pp) ma[i][r[i] - l[i]]++;
      }
    }
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
      int alll = 0, allr = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) alll += l[j], allr += r[j];
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) continue;
        int lnum = alll - l[j], rnum = allr - r[j];
        if (lnum - rnum < num[j]) {
          if (lnum - rnum >= 0) {
            ans = max(ans, dp[i - (1 << j)] + ma[j][lnum - rnum]);
          }
          continue;
        }
        dp[i] = max(dp[i], dp[i - (1 << j)] + ma[j][lnum - rnum]);
      }
    }
    for (int i = 0; i < 1048576; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans - 1);
  }
  return 0;
}
