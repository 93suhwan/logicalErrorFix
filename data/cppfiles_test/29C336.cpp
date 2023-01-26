#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int one = 0, zero = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == 1) ++one;
      if (x == 0) ++zero;
    }
    ans = one * pow(2, zero);
    cout << ans << endl;
  }
  return 0;
}
