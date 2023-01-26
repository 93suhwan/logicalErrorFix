#include <bits/stdc++.h>
using namespace std;
int primes[1000000];
void calcPrimes() {
  primes[0] = primes[1] = 1;
  for (int i = 2; i * i < 1000000; i++) {
    if (primes[i] == 0)
      for (int j = i * i; j <= 1000000; j += i) primes[j] = 1;
  }
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << '\n';
      continue;
    }
    long long int sum = 0;
    if (n == 1)
      sum = 1;
    else if (n == 2)
      sum = -1;
    else if (n == 3)
      sum = -4;
    else if (n == 4)
      sum = 0;
    if (x % 2 == 0) sum = -sum;
    if (n > 4) {
      long long int k = n / 4;
      long long int last = 4 * k + 1;
      sum = last;
      if (x % 2 == 0) sum = -sum;
      long long int rem = n - last;
      if (rem == 1) {
        if (x & 1)
          sum += -(last + 1);
        else
          sum += (last + 1);
      } else if (rem == 2) {
        if (x & 1)
          sum += -(2 * last + 3);
        else
          sum += (2 * last + 3);
      } else if (rem == 3) {
        if (x & 1)
          sum += -last;
        else
          sum += last;
      }
    }
    cout << x + sum << '\n';
  }
}
int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
  return 0;
}
