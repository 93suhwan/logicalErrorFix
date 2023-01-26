#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a, b;
void solve(int n, int a, int b) {
  int num1 = 1, num2 = 3;
  if (abs(a - b) > 1) {
    cout << -1 << '\n';
    return;
  }
  if (b > a) {
    int cnt = b * 2 + 1;
    if (n < cnt || n > cnt + 1) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1) {
        cout << num2 << ' ';
        num2 += 1;
      } else {
        cout << num1 << ' ';
        num1 += 1;
      }
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num2 << ' ';
      num2 += 1;
    }
    cout << '\n';
    return;
  }
  if (a > b) {
    int cnt = a * 2 + 1;
    if (n < cnt || n > cnt + 1) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1) {
        cout << num1 << ' ';
        num1 += 1;
      } else {
        cout << num2 << ' ';
        num2 += 1;
      }
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num1 << ' ';
      num1 += 1;
    }
    cout << '\n';
    return;
  }
  if (a == b) {
    int cnt = 2 * a + 1;
    if (n < cnt || n > cnt + 1) {
      cout << -1 << '\n';
      return;
    }
    for (int i = 1; i <= cnt; i++) {
      if (i & 1) {
        cout << num1 << ' ';
        num1 += 1;
      } else {
        cout << num2 << ' ';
        num2 += 1;
      }
    }
    for (int i = cnt + 1; i <= n; i++) {
      cout << num2 << ' ';
      num2 += 1;
    }
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
