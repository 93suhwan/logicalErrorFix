#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long mpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
pair<int, int> get_intersect(int x1, int y1, int x2, int y2, int r, int c) {
  if (x1 == x2 && y1 == y2) return make_pair(r, c);
  int x3 = x1 + r - 1, y3 = y1 + c - 1;
  int x4 = x2 + r - 1, y4 = y2 + c - 1;
  int lx = 0, ly = 0;
  if (x1 <= x2 && x2 <= x3) lx = x3 - x2 + 1;
  if (y1 <= y2 && y2 <= y3)
    ly = y3 - y2 + 1;
  else if (y2 <= y1 && y1 <= y4)
    ly = y4 - y1 + 1;
  return make_pair(lx, ly);
}
long long get_free(int r, int c, int first, int second) {
  long long ans = 1LL * r * c;
  int p = r - first, q = c - second;
  for (int i = 1; i <= first; i++)
    for (int j = 1; j <= second; j++) {
      for (int k = 1;; k++)
        if (i + 1LL * k * p <= r && j + 1LL * k * q <= c)
          ans--;
        else
          break;
    }
  return ans;
}
int main() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long tot = n * m - 2 * r * c;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 && y1 == y2)
    cout << mpow(k, n * m) << endl;
  else
    cout << mpow(k, n * m - r * c) << endl;
  return 0;
}
