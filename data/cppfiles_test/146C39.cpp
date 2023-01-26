#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, B = 305;
int p[N], r[N], a[N];
void fix(int x) {
  int y = x;
  for (int i = 0; i < B; i++) y = r[y];
  for (int i = 0; i <= B; i++) {
    a[y] = x;
    y = p[y];
    x = p[x];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    r[--p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = i;
    for (int j = 0; j < B; j++) a[i] = p[a[i]];
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      swap(p[x], p[y]);
      swap(r[p[x]], r[p[y]]);
      fix(x);
      fix(y);
    } else {
      int x, k;
      cin >> x >> k;
      x--;
      while (k >= B) {
        x = a[x];
        k -= B;
      }
      while (k) {
        x = p[x];
        k--;
      }
      cout << x + 1 << "\n";
    }
  }
  return 0;
}
