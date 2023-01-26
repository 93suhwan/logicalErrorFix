#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
template <class T>
bool umin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
const int N = 1 << 19;
const int inf = 1e9;
int n, k, mx[N], mi[N], f[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < (1 << k); ++i) {
    mx[i] = -inf;
    mi[i] = inf;
    f[i] = inf;
  }
  while (n--) {
    int x;
    cin >> x;
    mx[x] = mi[x] = 0;
  }
  for (int i = 0; i < k; ++i) {
    for (int y = 0; y < (1 << k); ++y)
      if (y >> i & 1) {
        int x = y ^ (1 << i);
        f[x] = f[y] = min(f[x], f[y]);
        umin(f[x], mi[y] + (1 << i) - mx[x]);
        umin(f[y], mi[x] + (1 << i) - mx[y]);
        int mix = mi[x], miy = mi[y], mxx = mx[x], mxy = mx[y];
        umin(mi[x], miy + (1 << i));
        umin(mi[y], mix + (1 << i));
        umax(mx[x], mxy + (1 << i));
        umax(mx[y], mxx + (1 << i));
      }
  }
  for (int i = 0; i < (1 << k); ++i) cout << f[i] << " ";
  cout << "\n";
  return 0;
}
