#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
long long p(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b % 2) {
      r *= a;
      r %= M;
    }
    a *= a;
    a %= M;
    b /= 2;
  }
  return r;
}
long long P(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b % 2) r *= a;
    a *= a;
    b /= 2;
  }
  return r;
}
int main() {
  long long k, q, s;
  cin >> k;
  q = P(2, k + 1) - 3;
  s = p(2, q);
  s *= 3;
  s %= M;
  cout << s;
}
