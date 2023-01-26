#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (l <= r / 2) {
      cout << r % (r / 2 + 1) << '\n';
    } else {
      cout << r % l << '\n';
    }
  }
  return 0;
}
