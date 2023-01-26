#include <bits/stdc++.h>
using namespace std;
int test, l, r;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> test;
  while (test--) {
    cin >> l >> r;
    if (2 * l <= r + 1) {
      cout << (r + 1) / 2 - 1 << '\n';
    } else
      cout << r - l << '\n';
  }
  return 0;
}
