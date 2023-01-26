#include <bits/stdc++.h>
using namespace std;
long long n, d, i, j, m, l, t, sz = 1, a;
long long cnt(long long p) {
  long long res = 1;
  for (i = 0; i < p; i++) res *= 2;
  return res;
}
int main() {
  cin >> t;
  for (int k = 0; k < t; k++) {
    long long h1 = 0, h0 = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a == 1) h1++;
      if (a == 0) h0++;
    }
    cout << h1 * cnt(h0) << "\n";
  }
  return 0;
}
