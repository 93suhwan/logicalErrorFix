#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r >= 2 * l)
      cout << (r + 1) / 2 - 1 << "\n";
    else
      cout << r % l << "\n";
  }
  return 0;
}
