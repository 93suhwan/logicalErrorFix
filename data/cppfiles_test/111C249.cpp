#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int l = i + 1; l <= n; l++) {
        cout << "()";
      }
      for (int j = i; j > 0; j--) {
        cout << "(";
      }
      for (int k = i; k > 0; k--) {
        cout << ")";
      }
      cout << "\n";
    }
  }
  return 0;
}
