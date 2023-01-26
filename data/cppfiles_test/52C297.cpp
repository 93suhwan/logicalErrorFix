#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main(int argc, char **argv) {
  long long t;
  cin >> t;
  for (long long ii = 0; ii < t; ii++) {
    long long n, k;
    cin >> n >> k;
    long long solution = 0;
    long long MOD = 1000000007;
    long long mult = 1;
    while (k > 0) {
      if (k % 2 == 1) {
        solution += mult;
      }
      mult *= n;
      mult %= MOD;
      k /= 2;
      solution %= MOD;
    }
    cout << solution << endl;
  }
  return 0;
}
