#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long maxn = 1e5 + 50;
long long t, n, m, a, b, c, s, vis[maxn];
int main() {
  t = read();
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= m; i++) {
      cin >> a >> b >> c;
      vis[b] = 1;
    }
    for (int i = 1; i <= n; i++)
      if (!vis[i]) s = i;
    for (int i = 1; i <= n; i++) {
      if (i != s) cout << s << " " << i << endl;
    }
  }
}
