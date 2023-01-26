#include <bits/stdc++.h>
using namespace std;
const long long N = 300100;
long long te, x, n, k, d, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> te;
  for (; te--;) {
    cin >> x >> n;
    d = 0;
    m = n;
    if (n) d++, m--;
    k = m / 4;
    m %= 4;
    d += k * 4;
    if (x & 1)
      x += d;
    else
      x -= d;
    for (long long i = n - m + 1; i <= n; i++)
      if (x & 1)
        x += i;
      else
        x -= i;
    cout << x << "\n";
  }
}
