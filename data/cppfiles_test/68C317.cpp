#include <bits/stdc++.h>
using namespace std;
long long t, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> k;
    long long nr = 0;
    for (long long p = 100000; p; p /= 2)
      while ((nr + p) * (nr + p) < k) nr += p;
    if (k - nr * nr <= nr)
      cout << k - nr * nr << ' ' << nr + 1 << '\n';
    else
      cout << nr + 1 << ' ' << nr + 2 - (k - nr * nr - nr) << '\n';
  }
  return 0;
}
