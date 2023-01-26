#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r, ans;
    cin >> l >> r;
    if (r % 2 == 0)
      ans = r / 2 + 1;
    else
      ans = (r + 1) / 2;
    if (ans >= l && ans <= r)
      cout << r - ans << "\n";
    else
      cout << r % l << "\n";
  }
}
