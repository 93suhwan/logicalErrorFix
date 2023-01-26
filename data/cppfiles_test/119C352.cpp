#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      sum += x;
    }
    if (sum == n || sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
