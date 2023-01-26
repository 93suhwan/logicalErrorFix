#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long l, r, x;
    cin >> l >> r;
    x = r / 2 + 1;
    if (x >= l)
      cout << r % x << "\n";
    else
      cout << r % l << "\n";
  }
  return 0;
}
