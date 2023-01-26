#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a, b;
void solve(int n, int a, int b) {
  if (abs(a - b) > 1) {
    cout << -1 << '\n';
    return;
  }
  if (b > a) {
    int cnt = b * 2 + 1;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1)
        cout << 1 << ' ';
      else
        cout << 0 << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) cout << 1 << ' ';
    cout << '\n';
    return;
  }
  if (a > b) {
    int cnt = a * 2 + 1;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1)
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) cout << 0 << ' ';
    cout << '\n';
    return;
  }
  if (a == b) {
    int cnt = 2 * a + 2;
    if (n < cnt) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1)
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    for (int i = cnt + 1; i <= n; i++) cout << 1 << ' ';
    cout << '\n';
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    solve(n, a, b);
  }
  return 0;
}
