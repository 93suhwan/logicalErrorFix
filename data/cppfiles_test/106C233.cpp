#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void input() {}
int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};
long long power(long long b, long long p) {
  long long an = 1;
  while (p > 0) {
    if (p % 2) {
      an *= b;
      an %= 1000000000;
    }
    b *= b;
    b %= 1000000000;
    p /= 2;
  }
  return an;
}
vector<bool> is_prime;
void sieve(long long n) {
  is_prime.assign(n, true);
  is_prime[0] = is_prime[1] = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 2; i < n + 2; i++) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
