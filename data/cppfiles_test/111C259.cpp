#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        cout << "(";
      }
      for (int j = 1; j <= i; ++j) {
        cout << ")";
      }
      for (int j = i + 1; j <= n; ++j) {
        cout << "(";
      }
      for (int j = i + 1; j <= n; ++j) {
        cout << ")";
      }
      cout << "\n";
    }
  }
  return 0;
}
