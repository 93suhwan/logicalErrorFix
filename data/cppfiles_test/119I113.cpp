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
    (x % 2 && sum != n) ? cout << 1 << endl : cout << 0 << endl;
  }
  return 0;
}
