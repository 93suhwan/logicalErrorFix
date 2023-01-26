#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void fil() {}
long long int ipow(long long int base, long long int k, long long int M) {
  base %= M;
  k = k % (M - 1);
  long long int total = 1;
  while (k) {
    if (k & 1) {
      total = (total * base) % M;
    }
    base = (base * base) % M;
    k >>= 1;
  }
  return total;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  fil();
  long long int t = 1;
  cin >> t;
  for (int i = 1; i < t + 1; i++) {
    solve();
  }
}
void solve() {
  int n, m, ix, iy, fx, fy;
  cin >> n >> m >> ix >> iy >> fx >> fy;
  int dx = 1, dy = 1;
  int cnt = 0;
  while (1) {
    if (ix == fx || iy == fy) {
      cout << cnt << "\n";
      return;
    }
    if (!(ix + dx <= n && ix + dx >= 1)) {
      dx *= -1;
    }
    if (!(iy + dy <= m && iy + dy >= 1)) {
      dy *= -1;
    }
    ix += dx;
    iy += dy;
    cnt++;
  }
}
