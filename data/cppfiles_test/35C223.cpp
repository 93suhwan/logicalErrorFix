#include <bits/stdc++.h>
using namespace std;
struct H {
  long long x, y;
};
long long m, n, v, t, x;
H w[30];
int C(H a, H b) { return a.x < b.x; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m;
    v = x = 0;
    for (int p = 1 << 29; p; p >>= 1) {
      if (x + (p - 1) <= m) {
        w[v++] = {(n ^ x) & ~(p - 1), (n ^ x) | (p - 1)};
        x |= p;
      }
    }
    sort(w, w + v, C);
    w[v].x = 1 << 30;
    x = -1;
    for (int i = 0; i <= v; i++) {
      if (x + 1 != w[i].x) break;
      x = w[i].y;
    }
    cout << x + 1 << '\n';
  }
}
