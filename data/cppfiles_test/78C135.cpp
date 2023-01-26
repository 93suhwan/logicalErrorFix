#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r, mx = 0;
    cin >> l >> r;
    cout << r % (max(l, r / 2 + 1)) << "\n";
  }
  return 0;
}
