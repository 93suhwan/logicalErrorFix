#include <bits/stdc++.h>
using namespace std;
void test() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n / m, r = n % m, b = 1;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < r; ++j) {
      cout << a + 1 << ' ';
      for (int l = 0; l < a + 1; ++l) {
        cout << b << ' ';
        if (++b == n + 1) {
          b = 1;
        }
      }
      cout << '\n';
    }
    int c = b;
    for (int j = 0; j < m - r; ++j) {
      cout << a << ' ';
      for (int l = 0; l < a; ++l) {
        cout << c << ' ';
        if (++c == n + 1) {
          c = 1;
        }
      }
      cout << '\n';
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    test();
  }
  return 0;
}
