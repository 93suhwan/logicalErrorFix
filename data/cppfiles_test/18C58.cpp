#include <bits/stdc++.h>
using namespace std;
int u[50005], f[50005];
int n, m;
bool jud(int x, int y) {
  int m1 = x, mx1 = u[x];
  int m2 = y, mx2 = u[y];
  if (mx2 < m2) swap(mx2, m2);
  if (mx1 < m1) swap(mx1, m1);
  if (mx2 > mx1 && m2 < m1) return false;
  if (mx1 > mx2 && m1 < m2) return false;
  return true;
}
void solve() {
  int ans = 0, cnt = 0;
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) {
    u[i] = f[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    u[a] = b;
    u[b] = a;
    if (b < a) swap(a, b);
    for (int j = a + 1; j < b; j++) {
      if (u[j] == 0) continue;
      if (jud(a, j)) ans++;
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!u[i]) {
      f[++cnt] = i;
    }
  }
  for (int i = 1; i <= cnt / 2; i++) {
    int a = f[i], b = f[i + cnt / 2];
    u[a] = b;
    u[b] = a;
    if (a > b) swap(a, b);
    for (int j = a + 1; j < b; j++) {
      if (u[j] == 0) continue;
      if (jud(a, j)) ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
