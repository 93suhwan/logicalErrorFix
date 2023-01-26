#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (r - l == 0)
      cout << 0;
    else if (r - l == 1)
      cout << 1;
    else if (r % 2 == 1) {
      long long b = r / 2 + 1;
      cout << r % b;
    } else {
      long long b = r / 2;
      cout << (r - 1) % b;
    }
    cout << "\n";
  }
  return 0;
}
