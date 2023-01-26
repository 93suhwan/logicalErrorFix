#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
namespace fast_IO {
long long read() {
  long long num = 0;
  char c;
  bool tag = false;
  while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
    ;
  if (!~c) return EOF;
  if (c == '-')
    tag = true;
  else if (c == '+')
    tag = false;
  else
    num = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    num = (num << 1) + (num << 3) + (c ^ 48);
  if (tag) return -num;
  return num;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace fast_IO
int a[N], b[N], pre[N], dp[N], ans[N];
set<int> st;
int q[N], tt[N];
bool tag[N];
void print(int x, int ed) {
  if (x == ed) return;
  print(pre[x], ed);
  printf("%d ", ans[x]);
}
int main() {
  int n = fast_IO::read();
  for (int i = 1; i <= n; ++i) a[i] = fast_IO::read(), st.insert(i);
  for (int i = 1; i <= n; ++i) b[i] = fast_IO::read();
  memset(dp, 0x3f, sizeof(dp));
  dp[n] = 0;
  int head = 0, tail = 0;
  q[head++] = n;
  tag[n] = true;
  while (head != tail) {
    auto x = q[tail++];
    if (x == a[x]) {
      if (dp[0] > dp[x] + 1) {
        dp[0] = dp[x] + 1;
        pre[0] = x;
      }
      continue;
    }
    auto it = st.lower_bound(x - a[x]);
    *tt = 0;
    for (; it != st.end() && *it <= x; it++) {
      if (dp[*it + b[*it]] > dp[x] + 1) {
        dp[*it + b[*it]] = dp[x] + 1;
        pre[*it + b[*it]] = x;
        ans[*it + b[*it]] = *it;
        if (!tag[*it]) {
          q[head++] = *it + b[*it];
          tag[*it] = true;
        }
      }
      tt[++*tt] = *it;
    }
    while (*tt) {
      if (st.find(tt[*tt]) != st.end()) st.erase(tt[*tt]);
      --*tt;
    }
  }
  if (dp[0] == INF)
    puts("-1");
  else {
    printf("%d\n", dp[0]);
    print(0, n);
  }
  return 0;
}
