#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
const long long mod = 998244353;
const long long inf = (long long)4e17 + 5;
const int INF = 1e9 + 7;
const double pi = acos(-1.0);
long long inv(long long b) {
  if (b == 1) return 1;
  return (mod - mod / b) * inv(mod % b) % mod;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int ans[105];
int more[maxn], les[maxn];
int mmax, mmin;
int nex[maxn], pre[maxn];
inline void ask_m(int x) {
  printf("?");
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    if (i == x)
      printf(" 2");
    else
      printf(" 1");
  }
  puts("");
  fflush(stdout);
  scanf("%d", more + x);
  if (more[x] == 0) {
    ans[x] = n;
    mmax = x;
  }
}
inline void ask_l(int x) {
  printf("?");
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    if (i == x)
      printf(" 1");
    else
      printf(" 2");
  }
  puts("");
  fflush(stdout);
  scanf("%d", les + x);
  if (les[x] == 0) {
    ans[x] = 1;
    mmin = x;
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    ask_m(i);
  }
  for (int i = 1; i <= n; i++) {
    ask_l(i);
  }
  for (int i = 1; i <= n; i++) {
    if (more[i] == i || !more[i]) continue;
    nex[i] = more[i];
    pre[more[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (les[i] == i || !les[i]) continue;
    nex[les[i]] = i;
    pre[i] = les[i];
  }
  int fr;
  for (int i = 1; i <= n; i++) {
    if (!nex[i]) {
      fr = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    ans[fr] = i;
    fr = pre[fr];
  }
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
  puts("");
  fflush(stdout);
}
int main() {
  scanf("%d", &n);
  solve();
  return 0;
}
