#include <bits/stdc++.h>
using namespace std;
template <typename T>
T MIN(T a, T b) {
  return ((a < b) ? a : b);
}
template <typename T>
T MAX(T a, T b) {
  return ((a > b) ? a : b);
}
const int maxn = 200010;
long long n;
long long k;
long long buk[maxn];
int maxhh;
int head[maxn], to[maxn * 2], nxt[maxn * 2], top;
inline void add(int x, int y) {
  to[++top] = y;
  nxt[top] = head[x];
  head[x] = top;
}
int dfs(int now, int fa) {
  int maxh = 0;
  for (int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    maxh = MAX(maxh, dfs(to[i], now));
  }
  buk[maxh + 1]++;
  return maxh + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  maxhh = dfs(1, 1);
  long long res = 0;
  for (int i = 1; i <= maxhh; i++) {
    if (buk[i] > k) {
      res += buk[i] - k;
    }
  }
  long long red = MIN(MAX(n / 2, buk[1]), k);
  long long w = n - red;
  long long b = MIN(red, res);
  w -= b;
  int c = MIN(w / 2, res - b);
  w -= c;
  b += c;
  cout << w * (red - b);
}
