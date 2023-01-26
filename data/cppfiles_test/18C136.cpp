#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 5e6 + 5;
const int inf = 0x3f3f3f3f;
const long long inF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int lowbit(int x) { return (x & -x); }
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
template <typename T>
T rd(T x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
  return;
}
int ans[maxn], a[maxn];
bool vis[maxn];
void solve(int t) {
  int n = rd((int)1), d = rd((int)1);
  for (int i = 0; i < n; i++) a[i] = rd((int)1), ans[i] = inf, vis[i] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) continue;
    int j = (i + d) % n;
    int cnt = 0;
    ans[i] = 0;
    while (!vis[j]) {
      cnt++;
      if (a[j] == 0)
        break;
      else
        ans[j] = min(ans[j], cnt), vis[j] = 1;
      j = (j + d) % n;
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) mx = max(mx, ans[i]);
  if (mx == inf)
    cout << "-1\n";
  else
    cout << mx << '\n';
  return;
}
int main() {
  int t = rd((int)1);
  while (t--) solve(t);
  return 0;
}
