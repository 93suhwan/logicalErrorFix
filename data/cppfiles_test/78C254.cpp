#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, l, r, x;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    cin >> l >> r;
    if (l > (r / 2)) {
      cout << r % l << endl;
    } else {
      cout << (r) % ((r / 2) + 1) << endl;
    }
  }
}
