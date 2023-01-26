#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int m = 3e2;
int crr = 0;
int t, n, q, type, x, y;
int L[maxn];
int R[maxn];
int upbl[maxn];
void update(int x) {
  int lhead = x;
  for (int i = 0; i < m; i++) x = R[x];
  for (int i = 0; i < m; i++) {
    upbl[lhead] = x;
    x = L[x];
    lhead = L[lhead];
  }
}
int main() {
  t = 1;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> R[i];
      upbl[i] = 0;
      L[R[i]] = i;
    }
    for (int i = 1; i <= n; i++)
      if (!upbl[i]) update(i);
    for (int i = 0; i < q; i++) {
      cin >> type >> x >> y;
      if (type == 1) {
        swap(R[x], R[y]);
        L[R[x]] = x;
        L[R[y]] = y;
        update(x);
        update(y);
      } else {
        while (y >= m) {
          x = upbl[x];
          y -= m;
        }
        while (y--) x = R[x];
        cout << x << "\n";
      }
    }
  }
}
