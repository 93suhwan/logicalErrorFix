#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, n, ans;
  long long m = 1e9 + 7;
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    n *= 2;
    ans = 1;
    while (n > 0) {
      ans = ans * n;
      if (ans / 2 > m) ans %= m;
      n--;
    }
    cout << ans / 2 % m << endl;
  }
  return 0;
}
