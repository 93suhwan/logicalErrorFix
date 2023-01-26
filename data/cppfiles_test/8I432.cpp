#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = n / 3, r = n / 3;
    if (l + (r * 2) == n) {
      cout << l << " " << r << endl;
    } else if (n - (l + (r * 2)) == 1) {
      cout << l + 1 << " " << r << endl;
    }
  }
  return 0;
}
