#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int range = (r / 2) + 1;
    if (l < range) {
      cout << (r % range) << endl;
    } else
      cout << (r % l) << endl;
  }
  return 0;
}
