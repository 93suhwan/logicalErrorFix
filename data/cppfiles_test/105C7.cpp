#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxsum = 2000005;
bool sort1 = true;
class dish {
 public:
  int i;
  int a;
  int b;
  int sum;
  int amin;
  int amax;
  int m;
  int resa;
  dish(int i, int a, int b, int m)
      : i(i),
        a(a),
        b(b),
        m(m),
        resa(0),
        amin(max(a - m, 0)),
        amax(a + min(b - m, 0)),
        sum(a + b - m) {}
  dish() {}
  bool operator<(const dish &d) const {
    if (sort1)
      return amax < d.amax;
    else
      return i < d.i;
  }
};
dish d[maxn];
int maxa[maxsum];
int main() {
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    scanf("%d", &n);
    sort1 = true;
    int a, b, m;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d", &a, &b, &m);
      d[i] = dish(i, a, b, m);
      maxa[d[i].sum] = -1;
    }
    sort(d, d + n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
      if (maxa[d[i].sum] >= d[i].amin)
        d[i].resa = maxa[d[i].sum];
      else {
        d[i].resa = d[i].amax;
        maxa[d[i].sum] = d[i].amax;
        ++r;
      }
    }
    sort1 = false;
    sort(d, d + n);
    cout << r << '\n';
    for (int i = 0; i < n; ++i) {
      int x = d[i].a - d[i].resa;
      int y = d[i].m - x;
      cout << x << ' ' << y << '\n';
    }
  }
  return 0;
}
