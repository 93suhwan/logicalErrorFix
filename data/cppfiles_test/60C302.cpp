#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int val = 0;
    val = (1 << 30) - 1;
    val = (val << 1) | 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      val = (val & x);
    }
    cout << val << "\n";
  }
}
