#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1) {
      cout << -1 << '\n';
      continue;
    } else if (a + b + 2 > n) {
      cout << -1 << '\n';
      continue;
    }
    int o = 3, e = 2;
    if (a == b) {
      for (long long int i = 1; i < 2 * a + 2; i++) {
        if (i == 1)
          cout << 1 << " ";
        else if (i & 1) {
          cout << e << " ";
          e += 2;
        } else {
          cout << o << " ";
          o += 2;
        }
      }
      for (long long int i = 2 * a + 2; i < n + 1; i++) cout << i << " ";
      cout << '\n';
    } else if (a > b) {
      for (long long int i = 1; i < 2 * b + 2; i++) {
        if (i == 1)
          cout << 1 << " ";
        else if (i & 1) {
          cout << e << " ";
          e += 2;
        } else {
          cout << o << " ";
          o += 2;
        }
      }
      for (long long int i = n + 1 - 1; i >= 2 * b + 2; i--) cout << i << " ";
      cout << '\n';
    } else if (a < b) {
      o = b + 1;
      e = 1;
      for (long long int i = 1; i < 2 * b + 1; i++) {
        if (i & 1) {
          cout << o << " ";
          o += 1;
        } else {
          cout << e << " ";
          e += 1;
        }
      }
      for (long long int i = 2 * b + 1; i < n + 1; i++) cout << i << " ";
      cout << '\n';
    }
  }
  return 0;
}
