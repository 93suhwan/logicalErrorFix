#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, n;
    cin >> l >> n;
    if (l <= n / 2) {
      cout << n % ((n / 2) + 1) << endl;
    } else {
      cout << n % l << endl;
    }
  }
}
