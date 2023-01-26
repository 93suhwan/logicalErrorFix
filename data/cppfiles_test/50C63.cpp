#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long Mod = 998244353;
int n;
int a[N];
long long dp[N], sum[N];
struct date {
  int num[4];
} nw;
stack<date> st;
template <typename T>
inline void read(T &x) {
  x = 0;
  T op = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') op = -1;
  for (; c <= '9' && c >= '0'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= op;
}
int main() {
  read(n);
  for (int i = 1; i < n + 1; ++i) read(a[i]);
  dp[0] = 1;
  long long s = 0;
  st.push(nw);
  for (int i = 1; i < n + 1; ++i) {
    int l = i;
    long long tmp = 0;
    while (!st.empty() && st.top().num[0] > a[i]) {
      int L = st.top().num[1], R = st.top().num[2];
      s = (s - st.top().num[3]) % Mod;
      tmp = (tmp + a[i] * (sum[R] - sum[L - 1])) % Mod;
      l = L;
      st.pop();
    }
    tmp = (tmp + a[i] * dp[i - 1] * (i & 1 ? -1 : 1)) % Mod;
    nw.num[0] = a[i], nw.num[1] = l, nw.num[2] = i, nw.num[3] = (int)tmp;
    st.push(nw);
    dp[i] = (s + tmp) * (i & 1 ? -1 : 1) % Mod;
    sum[i] = (sum[i - 1] + dp[i - 1] * (i & 1 ? -1 : 1)) % Mod;
    s = (s + tmp) % Mod;
  }
  printf("%lld\n", (dp[n] + Mod) % Mod);
  return 0;
}
