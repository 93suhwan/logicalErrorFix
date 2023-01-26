#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long num = r / 2;
    if (num >= l) {
      if (r % 2 == 0) {
        cout << num - 1 << endl;
      } else {
        cout << num << endl;
      }
    } else {
      cout << r % l << endl;
    }
  }
  return 0;
}
