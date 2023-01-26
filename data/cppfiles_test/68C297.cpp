#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long foo = ceil(sqrt(k));
    long long start = 1 + (foo - 1) * (foo - 1);
    long long row, col;
    if (start + (foo - 1) >= k) {
      col = foo;
      row = k - start + 1;
    } else {
      row = foo;
      k -= (start + (foo - 1));
      col = (foo - 1) - k + 1;
    }
    cout << row << " " << col << "\n";
  }
  return 0;
}
