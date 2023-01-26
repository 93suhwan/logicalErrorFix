#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e18;
struct node {
  long long x;
  int y;
} b[maxn];
long long a[maxn];
int t, n, k;
int cmp(node w, node m) {
  if (w.x == m.x) {
    return w.y > m.y;
  }
  return w.x > m.x;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i].x = 1ll * i - a[i];
      b[i].y = i;
    }
    sort(b + 1, b + n + 1, cmp);
    long long e = (a[b[1].y] | a[b[2].y]);
    long long w = b[1].y * b[2].y;
    printf("%lld\n", w - k * e);
  }
  return 0;
}
