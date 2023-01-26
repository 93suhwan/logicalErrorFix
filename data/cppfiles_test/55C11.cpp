#include <bits/stdc++.h>
using namespace std;
long long modulo(long long a, long long b, long long n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long g = (long long)(pow(2, n) + 0.5) - 1;
  long long ans = 6;
  long long M = 1e9 + 7;
  long long a = modulo(4, g - 1, M);
  a *= ans;
  a %= M;
  cout << a << "\n";
}
