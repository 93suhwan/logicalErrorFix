#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s += x;
    }
    cout << (s % n ? 1 : 0) << '\n';
  }
  return 0;
}
