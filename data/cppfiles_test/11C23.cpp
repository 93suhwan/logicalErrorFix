#include <bits/stdc++.h>
using namespace std;
struct H {
  int i, x, y;
};
int k, m, n, b[200004];
H w[200004];
int C(H a, H b) { return a.x < b.x || a.x == b.x && a.i > b.i; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  fill(b + 1, b + n + 1, 1 << 30);
  for (int i = 1; i <= n; i++) {
    cin >> k;
    w[i] = {i, k, i - k};
  }
  sort(w + 1, w + n + 1, C);
  for (int i = 1; i <= n; i++) {
    if (w[i].y >= 0) b[upper_bound(b + 1, b + n + 1, w[i].y) - b] = w[i].y;
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] < 1 << 30) m = i;
  }
  cout << m;
}
