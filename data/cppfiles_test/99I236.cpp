#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, n;
  cin >> x >> n;
  for (long long i = 1; i <= n; i++) {
    if (x % 2 == 0)
      x = x - i;
    else
      x = x + i;
  }
  cout << x;
  return 0;
}
