#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n & 1) {
      long long x = (n - 1) >> 1;
      cout << x << ' ' << x + 1 << '\n';
    } else {
      cout << 1 - n << ' ' << n << '\n';
    }
  }
  return 0;
}
