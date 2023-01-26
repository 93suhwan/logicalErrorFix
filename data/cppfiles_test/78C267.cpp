#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void inthe_code() {}
int32_t main() {
  inthe_code();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l <= (r / 2) + 1) {
      cout << r % ((r / 2) + 1) << "\n";
    } else {
      cout << r % l << "\n";
    }
  }
}
