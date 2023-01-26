#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
template <typename T>
void inline put(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) put(x / 10);
  putchar(x % 10 + '0');
  return;
}
const int maxn = 1e6 + 5;
int vis[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      vis[y] = 1;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
      if (vis[i] == 0) {
        pos = i;
        break;
      }
    for (int i = 1; i <= n; i++) {
      if (i == pos) continue;
      cout << pos << " " << i << endl;
    }
  }
}
