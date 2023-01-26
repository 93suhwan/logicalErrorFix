#include <bits/stdc++.h>
using namespace std;
long long fact(long long a) {
  long long mult = 1;
  if (a < 0) {
    a = -a;
    mult = -1;
  }
  long long p = a + 2;
  long long symy = a;
  for (long long i = 2; i * i * i < p; ++i) {
    while (a % (i * i) == 0) {
      a = a / (i * i);
      symy = symy / (i * i);
    }
    while (symy % (i) == 0) {
      symy = symy / (i);
    }
  }
  if (symy != 0) {
    if ((long long)sqrt(symy) * (long long)sqrt(symy) == symy) a = a / symy;
  }
  return a * mult;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long j;
    cin >> j;
    long long sum = 0;
    for (long long q = 0; q < j; ++q) {
      long long z;
      cin >> z;
      sum += z;
    }
    if (sum % j == 0)
      cout << "0"
           << "\n";
    else
      cout << "1"
           << "\n";
  }
  return 0;
}
