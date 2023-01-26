#include <bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;
int n, m, a, b, r[N];
void solve() {
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b > n - 2) {
    cout << -1 << endl;
    return;
  }
  if (a > b) {
    r[0] = 1, r[n - 1] = 2;
    for (int i = 0; i < a - 1; ++i) {
      r[2 * i + 1] = n - i, r[2 * (i + 1)] = i + 3;
    }
    r[2 * a - 1] = n - a + 1;
    for (int i = a * 2; i < n - 1; ++i) {
      r[i] = n - a - (i - a * 2);
    }
  }
  if (a == b) {
    r[0] = 1, r[n - 1] = n;
    for (int i = 0; i < a - 1; ++i) {
      r[2 * i + 1] = n - i - 1, r[2 * (i + 1)] = i + 2;
    }
    r[2 * a - 1] = n - a;
    for (int i = a * 2; i < n - 1; ++i) {
      r[i] = n - a - (i - a * 2) - 1;
    }
  }
  if (a < b) {
    r[0] = n - 1, r[n - 1] = n;
    for (int i = 0; i < b - 1; ++i) {
      r[2 * i + 1] = i + 1, r[2 * (i + 1)] = n - i - 2;
    }
    r[2 * b - 1] = b;
    for (int i = b * 2; i < n - 1; ++i) {
      r[i] = b + i - (b * 2) + 1;
    }
  }
  for (int i = 0; i < n; ++i) cout << r[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(2);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
