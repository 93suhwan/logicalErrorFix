#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (r < l * 2) {
      cout << (r - 1);
    } else {
      cout << (r - 1) / 2;
    }
  }
  return 0;
}
