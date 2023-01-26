#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int l = i;
      int r = n - l;
      for (int j = 1; j <= l; j++) {
        cout << "(";
      }
      for (int j = 1; j <= l; j++) {
        cout << ")";
      }
      for (int j = 1; j <= r; j++) {
        cout << "()";
      }
      cout << '\n';
    }
  }
  return 0;
}
