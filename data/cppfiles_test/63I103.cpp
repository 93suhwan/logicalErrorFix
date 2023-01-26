#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int inf = 0x3f3f3f3f;
const int N = 410000;
const int M = 20;
template <typename T>
inline bool scan_d(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF) return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <typename T>
void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T>
void println(T x) {
  print(x);
  putchar('\n');
}
struct TPoint {
  string s;
  int x, y, v1, v2;
  void solve() {
    x = y = v1 = v2 = 0;
    int n = s.length();
    vector<int> a(n + 2, -1);
    vector<int> b(n + 2, -1);
    a[0] = b[0] = 0;
    a[n + 1] = b[n + 1] = 0;
    stack<char> s1, s2, s3;
    for (int i = (0); i < (n); ++i) {
      if (!s1.empty() && s1.top() == '(' && s[i] == ')')
        s1.pop();
      else
        s1.push(s[i]);
      if (s1.empty() || s1.top() == ')') a[i + 1] = s1.size();
      if (s1.empty()) v1++;
    }
    for (int i = (n)-1; i >= (0); --i) {
      if (!s2.empty() && s2.top() == ')' && s[i] == '(')
        s2.pop();
      else
        s2.push(s[i]);
      if (s2.empty() || s2.top() == '(') b[i + 1] = s2.size();
    }
    int idx = 0;
    for (int i = (0); i < (n + 1); ++i) {
      if (a[i] != -1 && b[i + 1] != -1) {
        x = a[i], y = b[i + 1];
        idx = i;
        break;
      }
    }
    for (int i = (idx); i < (n); ++i) {
      if (!s3.empty() && s3.top() == '(' && s[i] == ')')
        s3.pop();
      else
        s3.push(s[i]);
      if (s3.empty()) v2++;
    }
  }
};
TPoint a[M];
int n, dp[(1ll << (M))], b[(1ll << (M))];
char sread[N];
void fmain() {
  scan_d(n);
  for (int i = (0); i < (n); ++i) {
    scanf("%s", sread);
    a[i].s.assign(sread);
    a[i].solve();
  }
  int res = 0;
  for (int cur = (1); cur < ((1ll << (n))); ++cur) {
    dp[cur] = 0;
    for (int i = (0); i < (n); ++i)
      if (cur & (1ll << (i))) {
        int las = cur ^ (1ll << (i));
        if (a[i].x > b[las]) {
          if (b[las] == 0)
            res = max(res, dp[las] + a[i].v1);
          else
            res = max(res, dp[las] + 1);
          continue;
        }
        int leave = b[las] - a[i].x;
        int val = dp[las];
        if (leave == 0) {
          if (a[i].x > 0) val++;
          val += a[i].v2;
        }
        if (dp[cur] <= val) {
          dp[cur] = val;
          b[cur] = leave + a[i].y;
        }
      }
  }
  res = max(res, dp[(1ll << (n)) - 1]);
  println(res);
}
int main() {
  fmain();
  char ch;
  while (scanf(" %c", &ch) != EOF) {
    ungetc(ch, stdin);
    fmain();
  }
  return 0;
}
