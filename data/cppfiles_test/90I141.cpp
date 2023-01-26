#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (max(x, y) % min(x, y) == 0) {
      cout << max(x, y) << "\n";
      continue;
    }
    if (x > y) {
      cout << x - 1 << "\n";
    } else {
      cout << y - 1 << "\n";
    }
  }
  return 0;
}
