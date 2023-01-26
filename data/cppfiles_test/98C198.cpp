#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int mod1 = 998244353;
long long fact(long long n) {
  long long f = 1;
  for (long long i = 1; i <= n; i++) f = (f * i) % mod;
  return f;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return (a * b) / gcd(a, b);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long ModPow(long long a, long long b, long long M) {
  if (M == 1) return 0;
  a %= M;
  long long ans = 1, t = 1;
  while (t > 0 && t <= b) {
    if (t & b) {
      ans *= a;
      ans %= M;
    }
    t <<= 1;
    a *= a;
    a %= M;
  }
  return ans;
}
long long modInverse(long long n, long long p) { return ModPow(n, p - 2, p); }
long long nCrModP(long long n, long long r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int aux(vector<int>& a, int p, int r) {
  int ma = a[p], ind = p;
  for (int i = p; i <= r; i++) {
    if (a[i] > ma) {
      ma = a[i];
      ind = i;
    }
  }
  return ind;
}
void MAX(vector<int>& a, int p, int r, int d, vector<int>& ans) {
  if (p <= r) {
    int q = aux(a, p, r);
    ans[q] = d;
    MAX(a, p, q - 1, d + 1, ans);
    MAX(a, q + 1, r, d + 1, ans);
  }
}
struct Comparator {
  bool operator()(const pair<int, int>& value, const int& key) {
    return (value.first < key);
  }
  bool operator()(const int& key, const pair<int, int>& value) {
    return (key < value.first);
  }
};
bool revsort(long long a, long long b) { return a > b; }
bool check(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return false;
  else
    return true;
}
template <typename T>
T debug(vector<T>& ans) {
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    int a = 0, b = 0;
    for (long long j = i; j < n; j++) {
      if (s[j] == 'a')
        a++;
      else
        b++;
      if (a == b) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "-1 -1\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
