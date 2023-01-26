#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m = 0, x;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
      cin >> x;
      if (x > i + m) {
        m = m + (x - (i + m));
      }
    }
    cout << m << endl;
  }
  return 0;
}
