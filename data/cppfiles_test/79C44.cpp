#include <bits/stdc++.h>
using namespace std;
inline int read(void) {
  register int x = 0, sgn = 1, ch = getchar();
  while (ch < 48 || 57 < ch) {
    if (ch == 45) sgn = 0;
    ch = getchar();
  }
  while (47 < ch && ch < 58) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return sgn ? x : -x;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int n, mx;
int a[300005], b[300005], v[300005];
int dp[300005], fr[300005], lst[300005];
vector<int> Ans;
struct ppp {
  int x, y;
  inline bool operator<(const ppp a) const {
    return y ^ a.y ? y > a.y : x < a.x;
  }
};
void pri(int x) {
  if (x == n) return;
  x = fr[x];
  pri(lst[x]);
  Ans.push_back(x);
}
priority_queue<ppp> pq;
signed main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = i - read();
  for (int i = 1; i <= n; ++i) b[i] = read() + i;
  pq.push(ppp{n, 0});
  mx = n;
  while (!pq.empty()) {
    ppp N = pq.top();
    pq.pop();
    int x = N.x;
    if (a[x] >= mx) continue;
    for (int i = a[x]; i < mx; ++i) {
      int k = b[i];
      if (!v[k]) {
        v[k] = 1;
        dp[k] = dp[x] + 1;
        fr[k] = i;
        lst[i] = x;
        pq.push(ppp{k, dp[k]});
      }
    }
    mx = a[x];
  }
  if (!dp[0]) {
    puts("-1");
  } else {
    pri(0);
    write(Ans.size());
    puts("");
    for (int x : Ans) {
      write(x);
      putchar(' ');
    }
  }
  return 0;
}
