#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T &x, T y) {
  x = x < y ? y : x;
  return;
}
template <typename T>
inline void ckmin(T &x, T y) {
  x = x < y ? x : y;
  return;
}
namespace FastIO {
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
char OPUT[100];
inline void print(long long x) {
  if (!x) return putchar('0'), putchar('\n'), void();
  if (x < 0) putchar('-'), x = -x;
  long long cnt = 0;
  while (x) OPUT[++cnt] = x % 10, x /= 10;
  for (register long long i = cnt; i >= 1; --i) putchar(OPUT[i] + '0');
  putchar('\n');
  return;
}
}  // namespace FastIO
using namespace FastIO;
const long long N = 4010;
long long ls[N], rs[N], tmp[N], dp[N][N], a[N], siz[N], n, m;
vector<long long> g[N];
inline void solve(long long x) {
  siz[x] = 1;
  for (long long t : {ls[x], rs[x]})
    if (t) {
      solve(t);
      for (long long i = 1; i <= min(m, siz[x]); ++i) tmp[i] = dp[x][i];
      long long upi = min(siz[x], m), upj = min(siz[t], m);
      for (long long i = 0; i <= upi; ++i)
        for (long long j = 1; i + j <= m && j <= upj; ++j)
          ckmax(tmp[i + j], dp[x][i] + dp[t][j] + (a[t] - a[x]) * j * (m - j));
      siz[x] += siz[t];
      for (long long i = 1; i <= min(m, siz[x]); ++i)
        dp[x][i] = tmp[i], tmp[i] = 0;
    }
  for (register long long i = min(m, siz[x]); i >= 1; --i)
    ckmax(dp[x][i], dp[x][i - 1]);
  return;
}
signed main() {
  n = read();
  m = read();
  for (register long long i = 1; i <= n; ++i) a[i] = read();
  stack<long long> st;
  for (long long i = 1; i <= n; ++i) {
    while (st.size() && a[st.top()] > a[i]) ls[i] = st.top(), st.pop();
    if (st.size()) rs[st.top()] = i;
    st.push(i);
  }
  while (st.size() > 1) st.pop();
  solve(st.top());
  print(dp[st.top()][m]);
  return 0;
}
