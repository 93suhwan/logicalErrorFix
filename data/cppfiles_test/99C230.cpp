#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    long long x, n;
    cin >> x >> n;
    long long cur = (n / 4) * 4;
    while (cur != n) {
      cur++;
      if (x % 2 == 0)
        x -= cur;
      else
        x += cur;
    }
    cout << x << '\n';
  }
  return 0;
}
