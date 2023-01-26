#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::swap;
using std::tie;
using std::tuple;
using std::vector;
using ll = long long;
const int N = 1003;
int n, m, q;
bool val[N][N];
ll ans = 0;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
struct Si {
  int d;
  int x, y;
  void go() {
    d ^= 1;
    x += dx[d];
    y += dy[d];
  }
  bool valid() { return 1 <= x && x <= n && 1 <= y && y <= m && val[x][y]; }
};
void testc() {
  int ax, ay;
  cin >> ax >> ay;
  ll lu1 = 1;
  for (Si s{0, ax - 1, ay}; s.valid(); s.go()) lu1++;
  ll lu2 = 1;
  for (Si s{3, ax, ay + 1}; s.valid(); s.go()) lu2++;
  ll ld1 = 1;
  for (Si s{1, ax, ay - 1}; s.valid(); s.go()) ld1++;
  ll ld2 = 1;
  for (Si s{2, ax + 1, ay}; s.valid(); s.go()) ld2++;
  val[ax][ay] ^= 1;
  if (val[ax][ay])
    ans += lu1 * lu2 + ld1 * ld2 - 1;
  else
    ans -= lu1 * lu2 + ld1 * ld2 - 1;
  cout << ans;
}
int main() {
  memset(val, 1, sizeof(val));
  cin >> n >> m >> q;
  for (int i = 2; i < n + m; i++) {
    int x1 = min(i - 1, n);
    int x2 = max(1, i - m);
    int y1 = min(i, n);
    int y2 = max(1, i + 1 - m);
    ll c = x1 + y1 - x2 - y2 + 2;
    ans += (c + 1) * c / 2;
  }
  ans -= n * m - 2;
  while (q--) {
    testc();
    if (q) putchar('\n');
  }
  return 0;
}
