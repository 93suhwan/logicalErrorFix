#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (k = 1; k <= i; k++) {
        cout << "(";
      }
      for (int kk = 1; kk < k; kk++) {
        cout << ")";
      }
      for (int jj = n; jj >= k; jj--) {
        cout << "()";
      }
      cout << endl;
    }
  }
}
