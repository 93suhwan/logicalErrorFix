#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << "()";
    cout << endl;
    int i = 0, z = n - 1;
    while (z--) {
      int y = i;
      while (y--) cout << "()";
      int x = (2 * n - i * 2) / 2;
      for (int k = 0; k < x; k++) cout << "(";
      for (int k = 0; k < x; k++) cout << ")";
      cout << endl;
      i += 1;
    }
  }
}
