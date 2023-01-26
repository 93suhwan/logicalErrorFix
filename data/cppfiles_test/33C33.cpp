#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const double pi = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int limit = 5e5;
int read() {
  int s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
const int mod = 998244353;
const int M = 20 + 5;
const int S = (1 << 20) + 5;
const int N = 1e5 + 5;
int n, m, k, _;
int a[N];
int dp[600];
signed main() {
  while (~scanf("%d", &n)) {
    for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
    memset(dp, 0x7f7f7f7f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 512; j++) {
        if (a[i] > dp[j]) dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
      }
    }
    vector<int> ans;
    for (int i = 0; i < 512; i++) {
      if (dp[i] != 0x7f7f7f7f) ans.push_back(i);
    }
    printf("%d\n", (ans.size()));
    for (auto it : ans) printf("%d ", it);
  }
  return 0;
}
