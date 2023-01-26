#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n - 2 || abs(a - b) > 1) {
      cout << -1 << endl;
      continue;
    }
    if (a > b) {
      cout << 1 << " ";
      for (int i = 1; i < a; ++i) {
        cout << 2 * i + 1 << " " << 2 * i << " ";
      }
      for (int i = n; i > 2 * (a - 1) + 1; --i) {
        cout << i << " ";
      }
      cout << endl;
    } else if (a == b) {
      cout << 1 << " ";
      for (int i = 1; i <= a; ++i) {
        cout << 2 * i + 1 << " " << 2 * i << " ";
      }
      for (int i = 2 * a + 2; i <= n; ++i) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << n << " ";
      for (int i = 1; i <= a; ++i) {
        cout << n - 2 * i << " " << n - 2 * i + 1 << " ";
      }
      for (int i = 1; i < n - 2 * a; ++i) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
}
