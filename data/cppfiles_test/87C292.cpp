#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int b = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b = max(b, a[i] - i - 1);
    }
    if (b > 0) {
      cout << b << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
