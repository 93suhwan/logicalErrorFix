#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    k--;
    if (k > 1) {
      if (m > n - 2) {
        cout << "yEs" << '\n';
      } else
        cout << "nO" << '\n';
    } else if (k == 1) {
      if (m >= n * (n - 1) / 2) {
        cout << "yEs" << '\n';
      } else
        cout << "nO" << '\n';
    } else {
      if (n == 1)
        cout << "yEs" << '\n';
      else
        cout << "nO" << '\n';
    }
  }
}
