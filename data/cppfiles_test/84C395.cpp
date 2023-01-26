#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long fastPower(long long base, long long power) {
  long long res = 1;
  while (power) {
    if (power & 1) res *= base;
    base *= base;
    power /= 2;
  }
  return res;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long isp(long long n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
bool good[N];
bool seive() {
  memset(good, true, sizeof good);
  good[1] = false;
  for (long long i = 2; i < N; i++) {
    if (good[i]) {
      for (long long j = 1ll * i * i; j < N; j += i) {
        good[j] = false;
      }
    }
  }
}
int commDiv(int a, int b) {
  int n = gcd(a, b);
  int result = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        result += 1;
      else
        result += 2;
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long ans = (n + 1) / 2;
    cout << s / (n - ans + 1) << endl;
  }
}
