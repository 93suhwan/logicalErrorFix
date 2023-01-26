#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n) {
  switch (n % 4) {
    case 0:
      return n;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return n + 1;
      break;
    default:
      return 0;
      break;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    int query = 0;
    cin >> a >> b;
    query += a;
    if (a - 1 >= 0 && computeXOR(a - 1) == b) {
      cout << query << "\n";
    } else if (a != (computeXOR(a - 1) ^ b)) {
      cout << query + 1 << "\n";
    } else {
      cout << query + 2 << "\n";
    }
  }
}
