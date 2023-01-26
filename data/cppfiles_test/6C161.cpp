#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
const int N = 2e5 + 10;
int n, m;
int q;
int res;
int les[N], more[N];
bool vis[N];
void solve() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v)
      les[u]++, more[v]++;
    else
      les[v]++, more[u]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (!more[i]) res++, vis[i] = 1;
  }
  cin >> q;
  while (q--) {
    int x;
    scanf("%d", &x);
    int a, b;
    if (x == 1) {
      scanf("%d%d", &a, &b);
      if (a > b)
        les[a]++, more[b]++;
      else
        les[b]++, more[a]++;
      if (vis[a] && more[a]) vis[a] = 0, res--;
      if (vis[b] && more[b]) vis[b] = 0, res--;
    }
    if (x == 2) {
      scanf("%d%d", &a, &b);
      if (a > b)
        les[a]--, more[b]--;
      else
        les[b]--, more[a]--;
      if (!vis[a] && !more[a]) res++, vis[a] = 1;
      if (!vis[b] && !more[b]) res++, vis[b] = 1;
    }
    if (x == 3) {
      cout << res << endl;
    }
  }
}
signed main() {
  solve();
  return 0;
}
