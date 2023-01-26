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
const int maxn = 1000000 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int maxm = 1000 + 10;
vector<int> prime;
int cnt, vis[maxm];
inline void init() {
  for (int i = 2; i < maxm; ++i) {
    if (!vis[i]) {
      cnt++;
      prime.push_back(i);
    }
    for (int j = 0; j < cnt && prime[j] * i < maxm; ++j) {
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int a[maxn], n, sum[maxn];
char b[maxn];
int dp[maxn];
inline void brute(int p) {
  for (int i = (1); i <= (n); ++i) {
    int now = 0;
    for (; a[i] % p == 0;) now++, a[i] /= p;
    if (b[i] == '/') now *= -1;
    sum[i] = sum[i - 1] + now;
  }
  sum[n + 1] = -inf;
  vector<int> sk;
  sk.push_back(n + 1);
  for (int i = (n); i >= (0); --i) {
    for (; sum[sk.back()] >= sum[i];) sk.pop_back();
    dp[i + 1] = min(dp[i + 1], sk.back() - 1);
    sk.push_back(i);
  }
}
vector<int> pos[maxn];
int f[maxn];
inline long long solve() {
  long long ans = 0;
  for (int i = (1); i <= (n); ++i) dp[i] = n;
  for (int i = (0); i < (cnt); ++i) {
    brute(prime[i]);
  }
  f[n + 1] = n;
  for (int i = (n); i >= (1); --i) {
    if (a[i] == 1) {
      f[i] = f[i + 1];
    } else {
      if (b[i] == '/') {
        f[i] = i - 1;
        pos[a[i]].push_back(i);
      } else {
        if (!pos[a[i]].empty()) pos[a[i]].pop_back();
        f[i] = f[i + 1];
        if (!pos[a[i]].empty()) {
          f[i] = min(f[i], pos[a[i]].back());
        }
      }
    }
  }
  for (int i = (1); i <= (n); ++i) {
    assert(min(f[i], dp[i]) + 1 >= i);
    ans += min(f[i], dp[i]) - i + 1;
  }
  return ans;
}
int main(void) {
  init();
  scanf("%d", &(n));
  for (int i = (1); i <= (n); ++i) scanf("%d", &(a[i]));
  scanf("%s", b + 1);
  printf("%lld\n", solve());
  return 0;
}
