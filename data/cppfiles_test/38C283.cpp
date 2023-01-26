#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n <= 6) {
      cout << 15 << '\n';
      continue;
    }
    long long x = n / 6;
    int r = n % 6;
    long long ans = x * 15;
    if (r > 0) {
      if (r <= 2)
        ans += 5;
      else if (r <= 4)
        ans += 10;
      else
        ans += 15;
    }
    cout << ans << '\n';
  }
}
