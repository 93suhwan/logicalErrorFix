#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long b, long long m) {
  if (b == 0) {
    return 1;
  }
  long long s = f(a, b / 2, m);
  s *= s;
  s %= m;
  if (b % 2) {
    s *= a;
  }
  return s % m;
}
int main() {
  vector<pair<int, int>> a;
  long long k, n, s;
  cin >> k;
  n = (1LL << k) - 2;
  s = f(4, n, 1000000007);
  s *= 6;
  s %= 1000000007;
  cout << s;
  return 0;
}
