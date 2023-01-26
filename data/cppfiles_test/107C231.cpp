#include <bits/stdc++.h>
using namespace std;
int t, n, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << -1 << endl;
      continue;
    }
    if (a - b == 1) {
      for (int i = 1; i <= b + 1; i++) cout << i << " " << n - b - 1 + i << " ";
      for (int i = n - b - 1; i > b + 1; i--) cout << i << " ";
      cout << endl;
    } else if (a == b) {
      for (int i = 1; i <= b + 1; i++) cout << i << " " << b + 1 + i << " ";
      for (int i = 2 * (b + 1) + 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      for (int i = 1; i <= b; i++) cout << b + i << " " << i << " ";
      for (int i = 2 * b + 1; i <= n; i++) cout << i << " ";
      cout << endl;
    }
  }
}
