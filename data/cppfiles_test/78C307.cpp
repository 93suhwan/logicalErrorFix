#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCase;
  cin >> testCase;
  while (testCase--) {
    long long l, r;
    cin >> l >> r;
    if ((r / 2) >= l) {
      long long m = r / 2;
      m++;
      long long ans = r % m;
      cout << ans << endl;
    } else {
      cout << (r % l) << endl;
    }
  }
}
