#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  int t;
  long long k, x, y;
  cin >> t;
  while (t--) {
    cin >> k;
    if (k % 2 == 1) {
      printf("%lld %lld", k / 2, k - k / 2);
    } else {
      printf("%lld %lld ", k / 3, k / 3 + 1);
    }
    cout << endl;
  }
}
