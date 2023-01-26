#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      sum = sum + a[i];
    }
    if (sum % n == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
