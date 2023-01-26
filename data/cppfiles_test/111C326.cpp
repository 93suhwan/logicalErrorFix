#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int k = i;
      while (k--) {
        cout << "(";
      }
      k = i;
      while (k--) {
        cout << ")";
      }
      k = n - i;
      while (k--) {
        cout << "()";
      }
      cout << endl;
    }
  }
}
