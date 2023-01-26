#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0, highest = 0;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      sum += x;
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
