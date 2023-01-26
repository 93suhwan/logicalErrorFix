#include <bits/stdc++.h>
using namespace std;
long long mfastPower(long long a, long long b, long long c) {
  long long res = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      res = ((res % c) * (a % c) % c);
    }
    a = ((a % c) * (a % c)) % c;
    b = b >> 1;
  }
  return res;
}
long long fastPower(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      res = res * a;
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (int i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  n--;
  long long ans = 6;
  for (long long i = 1; i < n + 1; i++) {
    long long u = 2 << (i - 1);
    long long o = mfastPower(4, u, 1000000007);
    ans *= o;
    ans = ans % 1000000007;
  }
  cout << (ans) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
