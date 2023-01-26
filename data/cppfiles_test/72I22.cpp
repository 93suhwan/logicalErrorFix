#include <bits/stdc++.h>
using namespace std;
long long ask(long long i, long long j) {
  cout << "? " << i << " " << j << endl;
  long long n;
  cin >> n;
  return n;
}
long long N = 1e9;
signed main() {
  long long d1 = ask(1, N);
  long long d2 = ask(N, N);
  long long ym = 1 + (N - 1 - d1 + d2) / 2;
  long long d3 = ask(N, ym);
  long long p = N - d3;
  long long q = N - d2 + d3;
  long long d4 = ask(p, 1);
  long long y = 1 + d4;
  long long x = 1 + ask(1, q);
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
}
