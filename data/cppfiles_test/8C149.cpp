#include <bits/stdc++.h>
using namespace std;
vector<long long int> v_prime;
void Sieve(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) v_prime.emplace_back(p);
}
vector<long long int> v_factor;
void factor(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v_factor.emplace_back(i);
      else {
        v_factor.emplace_back(i), v_factor.emplace_back(n / i);
      };
    }
  }
  sort(v_factor.begin(), v_factor.end());
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int log2n(long long int n) { return (n > 1) ? 1 + log2n(n / 2) : 0; }
long long int exp(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long int modinv(long long int x) { return exp(x, 1000000007 - 2); }
long long int add(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  a = ((a + b) % 1000000007 + 1000000007) % 1000000007;
  return a;
}
long long int sub(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  a = ((a - b) % 1000000007 + 1000000007) % 1000000007;
  return a;
}
long long int mul(long long int a, long long int b) {
  a %= 1000000007, b %= 1000000007;
  a = ((a * b) % 1000000007 + 1000000007) % 1000000007;
  return a;
}
long long int fac[1000009];
long long int ncr_mod(long long int n, long long int k) {
  long long int ans = fac[n];
  ans *= modinv(fac[k]);
  ans %= 1000000007;
  ans *= modinv(fac[n - k]);
  ans %= 1000000007;
  return ans;
}
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
void out(vector<long long int>& a) {
  for (long long int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << endl;
}
void sout(set<long long int> s) {
  for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
  cout << endl;
}
void mout(map<long long int, long long int> mm) {
  for (auto it = mm.begin(); it != mm.end(); ++it)
    cout << it->first << " " << it->second << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i, x, y, ok = 0, sum = 0, ans = 0, j, k, cnt = 0, m, c = 0,
                              q, z;
    long long int h[100009] = {0};
    cin >> n;
    x = n % 3;
    y = n / 3;
    long long int c1 = y;
    if (x == 2) {
      y += 1;
    } else if (x == 1)
      c1 += 1;
    cout << c1 << " " << y << endl;
  }
}
