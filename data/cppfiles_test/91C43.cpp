#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline int read() {
  char ch;
  bool sign = 0;
  int res = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = 1;
  while (isdigit(ch)) res = res * 10 + (ch ^ 48), ch = getchar();
  if (sign)
    return -res;
  else
    return res;
}
const int maxn = 100000 + 10;
const int mod = 998244353;
const int inf = 1e9;
const int maxm = 640;
int a[maxn], n;
vector<int> val;
inline int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  else if (x < 0)
    x += mod;
  return x;
}
inline int mul(int x, int y) { return 1LL * x * y % mod; }
int dp[2][maxm];
inline void clear(int t) {
  for (int i = (0); i < (maxm); ++i) {
    dp[t][i] = 0;
  }
}
inline int solve() {
  int t = 0;
  clear(t);
  int ans = 0;
  val.clear();
  for (int l = 1; l <= a[1];) {
    val.push_back(a[1] / l);
    l = a[1] / val.back() + 1;
  }
  for (int i = (2); i <= (n); ++i) {
    clear(t ^ 1);
    int now = 0;
    vector<int> nowval;
    int l = 1;
    int c = 0;
    for (; l <= a[i];) {
      nowval.push_back(a[i] / l);
      int j = nowval[c];
      l = a[i] / j + 1;
      int tmp = a[i - 1] / ((a[i - 1] + j - 1) / j);
      for (; val[now] != tmp && now >= 0;) {
        ++now;
      }
      assert(now >= 0);
      assert(val[now] == tmp);
      int v = a[i - 1] / j;
      if (a[i - 1] % j == 0) v--;
      dp[t ^ 1][c] = add(dp[t][now], mul(i - 1, v));
      c++;
    }
    ans = add(ans, dp[t ^ 1][0]);
    val = nowval;
    t ^= 1;
  }
  return ans;
}
int main(void) {
  int T;
  scanf("%d", &(T));
  for (; T--;) {
    scanf("%d", &(n));
    for (int i = (1); i <= (n); ++i) scanf("%d", &(a[i]));
    printf("%d\n", solve());
  }
  return 0;
}
