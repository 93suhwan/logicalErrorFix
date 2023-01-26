#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, ans[N], g[N];
void gsure(int a, int b, int p) {
  for (int i = a; i <= a + 1; i++) {
    bool ok = false;
    for (int j = b; j <= b + 1; j++) {
      cout << "? ";
      for (int k = a; k <= a + 2; k++)
        if (i != k) cout << k << " ";
      cout << j << "\n";
      fflush(stdout);
      int res;
      cin >> res;
      if (res != p) ok = true;
      fflush(stdout);
    }
    if (!ok) {
      for (int j = a; j <= a + 2; j++)
        if (j != i) ans[j] = (p == 1 ? 2 : 1);
    }
  }
  if (!ans[a] && !ans[a + 1]) {
    ans[a] = ans[a + 1] = p + 1;
    ans[a + 2] = (!p ? 2 : 1);
  } else
    for (int i = a; i <= a + 2; i++) {
      if (!ans[i]) ans[i] = (p == 0 ? 2 : 1);
    }
  return;
}
void check(int a, int b, int p, int q) {
  int x, y;
  cout << "? " << a << " " << a + 1 << " " << b << "\n";
  fflush(stdout);
  cin >> x;
  fflush(stdout);
  cout << "? " << a << " " << a + 2 << " " << b << "\n";
  fflush(stdout);
  cin >> y;
  fflush(stdout);
  if (x == p && y == p) ans[a] = ans[a + 1] = ans[a + 2] = p;
  if (x == q && y == q) ans[a + 1] = ans[a + 2] = p, ans[a] = q;
  if (x == q && y == p) ans[a + 1] = q, ans[a] = ans[a + 2] = p;
  if (x == p && y == q) ans[a + 2] = q, ans[a] = ans[a + 1] = p;
  return;
}
void solve() {
  cin >> n;
  fflush(stdout);
  int a, b;
  for (int i = 1; i <= n; i++) ans[i] = 0;
  for (int i = 1; i <= n; i += 3) {
    cout << "? " << i << " " << i + 1 << " " << i + 2 << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    g[i] = res;
    if (res)
      a = i;
    else
      b = i;
    fflush(stdout);
  }
  gsure(a, b, 1);
  gsure(b, a, 0);
  for (int i = 1; i <= n; i++)
    if (ans[i] == 2)
      a = i;
    else if (ans[i])
      b = i;
  for (int i = 1; i <= n; i += 3) {
    if (!ans[i]) {
      check(i, (g[i] ? b : a), g[i], !g[i]);
    }
  }
  int cnt = 0;
  cout << "! ";
  for (int i = 1; i <= n; i++)
    if (ans[i] == 1) cnt++;
  cout << cnt << " ";
  for (int i = 1; i <= n; i++)
    if (ans[i] == 1) cout << i << " ";
  cout << "\n";
  fflush(stdout);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) solve();
  return 0;
}
