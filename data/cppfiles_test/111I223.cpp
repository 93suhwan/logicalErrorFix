#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int i = 0; i < n; ++i) {
        cout << "(";
      }
      for (int i = n; i < 2 * n; ++i) {
        cout << ")";
      }
      cout << endl;
    }
  }
}
