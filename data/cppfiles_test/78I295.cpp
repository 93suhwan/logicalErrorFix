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
    if (r % 2 == 1) {
      long long b = r / 2 + 1;
      cout << r % b;
    } else {
      long long b = r / 2;
      if (b >= l)
        cout << (r - 1) % b;
      else
        cout << r % l;
    }
    cout << "\n";
  }
  return 0;
}
