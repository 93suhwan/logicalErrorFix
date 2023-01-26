#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0ll) {
    if (b % 2ll == 1ll) {
      result *= a;
    }
    a *= a;
    b /= 2ll;
  }
  return result;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
int log22(long long x) { return 64 - __builtin_clzll(x) - 1; }
void SieveOfEratosthenes(vector<long long>& mem) {
  long long n = 1e6 + 1;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long i = 2; i < n; i++)
    if (prime[i]) mem.push_back(i);
}
int primeFactors(int n) {
  int ans = 1;
  while (n % 2 == 0) {
    if (ans == 1) ans *= 2;
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      if (ans == 1 || ans == 2) ans *= i;
      n = n / i;
    }
  }
  if (n > 2) ans *= n;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> ma;
  for (long long i = 0; i < n; i++) {
    ma[s[i]]++;
  }
  string temp = "14689";
  for (auto x : temp) {
    if (ma[x]) {
      cout << 1 << '\n';
      cout << x << '\n';
      return;
    }
  }
  if (ma['2']) {
    for (long long i = 0; i < n; i++) {
      if (s[i] != '2') {
        cout << 2 << '\n';
        cout << s[i] << '2' << '\n';
        return;
      }
    }
    cout << 2 << '\n';
    cout << "22" << '\n';
    return;
  }
  if (ma['5']) {
    for (long long i = 0; i < n; i++) {
      if (s[i] != '5') {
        cout << 2 << '\n';
        cout << s[i] << '5' << '\n';
        return;
      }
    }
    cout << 2 << '\n';
    cout << "55" << '\n';
    return;
  }
  for (auto x : ma) {
    if (x.second >= 2) {
      cout << 2 << '\n';
      cout << x.first << x.first << '\n';
      return;
    }
  }
  cout << 2 << '\n';
  cout << s << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
