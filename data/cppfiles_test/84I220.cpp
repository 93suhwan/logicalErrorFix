#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  long long int n = 1ULL, a, b, mid, res;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == 1) {
      cout << b << endl;
    } else if (a >= b) {
      cout << 0 << endl;
    } else {
      mid = a / 2;
      mid++;
      res = b / mid;
      cout << res << endl;
    }
  }
  return 0;
}
