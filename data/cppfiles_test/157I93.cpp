#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char buffer[maxn], *S, *T;
inline char Get_Char() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, maxn, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  register char c;
  register int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f) return -re;
  return re;
}
inline void read(int& x) {
  register char c;
  register int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
inline void read(long long& x) {
  register char c;
  register long long re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
const int mxn = 5005;
const int md = 998244353;
int c[mxn][mxn], n, k;
string s;
inline void solve() {
  c[0][0] = 1;
  c[1][0] = c[1][1] = 1;
  for (int i = 2; i < mxn; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % md;
  }
  cin >> n >> k >> s;
  s = " " + s;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] != '1') continue;
    int cnt = 0;
    int j = i;
    for (; j <= n; ++j) {
      if (s[j] == '1') ++cnt;
      if (cnt == k) break;
    }
    if (j == n + 1) break;
    if (cnt < k) break;
    int ti = i - 1, tj = j + 1;
    for (; ti and s[ti] == '0';) --ti;
    for (; tj <= n and s[tj] == '0';) ++tj;
    ++ti, --tj;
    for (int tk = tj; tk >= ti; --tk) {
      if (tk == j) continue;
      ans += c[tk - ti][k - 1];
      ans %= md;
    }
  }
  (ans += 1) %= md;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  for (; T--;) solve();
  return 0;
}
