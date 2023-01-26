#include <bits/stdc++.h>
using namespace std;
long long fact(long long n);
long long ncr(long long n, long long r);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool isprime(long long n);
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void solve() {
  long long n;
  std::cin >> n;
  string s;
  std::cin >> s;
  long long i = 0, j = 0;
  for (long long k = 0; k < n; k++) {
    if (s[k] != '?') {
      i = k - 1;
      j = k + 1;
      break;
    }
  }
  if (i == 0 && j == 0) {
    s[0] = 'R';
    for (i = 1; i < n; i++) {
      if (s[i - 1] == 'R') {
        s[i] = 'B';
      } else {
        s[i] = 'R';
      }
    }
    std::cout << s << '\n';
    return;
  }
  while (i >= 0) {
    if (s[i] != '?') {
      i--;
      continue;
    } else if (s[i + 1] == 'R') {
      s[i] = 'B';
    } else if (s[i + 1] == 'B') {
      s[i] = 'R';
    }
    i--;
  }
  while (j < n) {
    if (s[j] != '?') {
      j++;
      continue;
    } else if (s[j - 1] == 'R') {
      s[j] = 'B';
    } else if (s[j - 1] == 'B') {
      s[j] = 'R';
    }
    j++;
  }
  std::cout << s << '\n';
}
int32_t main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
