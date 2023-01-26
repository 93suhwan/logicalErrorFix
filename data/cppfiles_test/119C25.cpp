#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c = 0;
    cin >> a;
    for (int x = 0; x < a; x++) {
      cin >> b;
      c = c + b;
    }
    if (c % a == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
