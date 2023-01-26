#include <bits/stdc++.h>
using namespace std;
int main() {
  const unsigned int M = 1000000007;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    long long int e;
    if (n % 2 == 0) {
      e = n / 2 - 1;
    } else {
      e = n / 2;
    }
    if (a > e || b > e || a + b > n - 2 || abs(b - a) > 1) {
      cout << -1 << "\n";
    } else {
      int v[n];
      if (a == b) {
        for (int i = 0; i <= n - 1; i++) {
          v[i] = i + 1;
        }
      } else if (a > b) {
        v[n - 1] = 1;
        for (int i = 0; i <= n - 2; i++) {
          v[i] = i + 2;
        }
        a--;
      } else {
        v[0] = n;
        for (int i = 1; i <= n - 1; i++) {
          v[i] = i;
        }
      }
      int i = 1;
      if (b > a) {
        i = 2;
      }
      while (a--) {
        swap(v[i], v[i + 1]);
        i += 2;
      }
      for (int i = 0; i <= n - 1; i++) {
        cout << v[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
