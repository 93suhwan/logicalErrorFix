#include <bits/stdc++.h>
using namespace std;
typedef struct NODE {
  NODE* prev = nullptr;
  unsigned numv = 1;
  unsigned ans = 0;
  bool chosen = false;
} NODE;
NODE a[2 * 400005];
NODE* get(NODE* x) {
  return (x->prev == nullptr) ? x : (x->prev = get(x->prev));
}
void merge(NODE* x, NODE* y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  if (x->numv < y->numv) {
    x->prev = y;
    y->numv += x->numv;
    y->ans += x->ans;
  } else {
    y->prev = x;
    x->numv += y->numv;
    x->ans += y->ans;
  }
}
void solve() {
  int n, m, i, j;
  int ans = 0;
  string s;
  bool flag = false;
  cin >> n >> m;
  for (int k = 1; k <= 2 * n; k++) a[k] = NODE();
  for (int k = n + 1; k <= 2 * n; k++) a[k].ans = 1;
  for (int k = 0; k < m; k++) {
    cin >> i >> j >> s;
    if (s == "imposter") {
      merge(a + i, a + j + n);
      merge(a + i + n, a + j);
    } else {
      merge(a + i, a + j);
      merge(a + i + n, a + j + n);
    }
  }
  for (int k = 1; k <= n; k++) {
    if (get(a + k) == get(a + k + n)) {
      flag = true;
      cout << "-1\n";
      break;
    }
  }
  if (flag) return;
  for (int k = 1; k <= n; k++) {
    NODE* crewi = get(a + k);
    NODE* impi = get(a + (k + n));
    if (crewi->chosen || impi->chosen) continue;
    if (crewi->ans > impi->ans) {
      ans += crewi->ans;
      crewi->chosen = true;
    } else {
      ans += impi->ans;
      impi->chosen = true;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
