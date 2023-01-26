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
const int N = 2e6 + 10;
int n, m;
int more[N];
void solve() {
  cin >> n >> m;
  int res = 0;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v)
      more[v]++;
    else
      more[u]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (!more[i]) res++;
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    scanf("%d", &x);
    int a, b;
    if (x == 1) {
      scanf("%d%d", &a, &b);
      if (a > b) {
        more[b]++;
        if (more[b]) res--;
      } else {
        more[a]++;
        if (more[a]) res--;
      }
    }
    if (x == 2) {
      scanf("%d%d", &a, &b);
      if (a > b) {
        more[b]--;
        if (!more[b]) res++;
      } else {
        more[a]--;
        if (!more[a]) res++;
      }
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
