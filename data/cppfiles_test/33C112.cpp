#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  if (b > a) {
    swap(a, b);
  }
  if (b == 0) {
    return a;
  }
  return GCD(b, a % b);
}
long long mul_mod(long long a, long long b, long long m) {
  a %= m;
  b %= m;
  return ((((a * b) % m) + m) % m);
}
long long power(long long base, long long n, long long m) {
  long long res = 1;
  while (n) {
    if (n & 1) res = mul_mod(res, base, m);
    base = mul_mod(base, base, m);
    n = n >> 1;
  }
  return res;
}
long long ncr(long long x, long long y) {
  long long ans = 1;
  y = (y > x - y ? x - y : y);
  for (long long i = 0; i < y; i++) {
    ans = (ans * (x - i)) % 1000000007;
    ans = (ans * power(i + 1, 1000000007 - 2, 1000000007)) % 1000000007;
    ans = ans % 1000000007;
  }
  return ans;
}
bool isPrime(long long n) {
  if (n == 1 or n == 0) return false;
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0 or n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 or n % (i + 2) == 0) return false;
  }
  return true;
}
long long add_mod(long long a, long long b, long long m) {
  a % m;
  b % m;
  return ((((a + b) % m) + m) % m);
}
long long sub_mod(long long a, long long b, long long m) {
  a % m;
  b % m;
  return ((((a - b) % m) + m) % m);
}
vector<long long> prmFactors(long long n) {
  vector<long long> res;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res.push_back(i);
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> mn(513, 1e9);
  vector<long long> ans;
  ans.push_back(0);
  mn[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 513; j++) {
      if (mn[j] < a[i]) {
        mn[j ^ a[i]] = min(mn[j ^ a[i]], a[i]);
      }
    }
  }
  for (int i = 1; i < 513; i++)
    if (mn[i] != 1e9) ans.push_back(i);
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
int main() {
  run();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0LL;
}
