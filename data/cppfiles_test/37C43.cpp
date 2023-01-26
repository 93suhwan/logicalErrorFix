#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool is_prime(int n) {
  if (n == 0 || n == 1) {
    return false;
  } else {
    for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<bool> v(n, true);
    int pos = -1;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      v[b - 1] = false;
    }
    for (int i = 0; i < n; i++) {
      if (v[i] == true) {
        pos = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (pos != i) {
        cout << pos + 1 << " " << i + 1 << "\n";
      }
    }
  }
  return 0;
}
