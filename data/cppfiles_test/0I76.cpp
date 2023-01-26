#include <bits/stdc++.h>
using namespace std;
const int64_t M = 1e9 + 7;
const int64_t INF = 1e6 + 100;
const int MAXN = 2e5 + 5;
bool prime[INF];
int64_t spf[INF];
int64_t d[INF] = {};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
string ds = "RLDU";
long long C(int n, int m) {
  if (m > n) return 0;
  long long z = 1;
  for (int i = 0; i < m; i++) z = z * (n - i) / (i + 1);
  return z;
}
long long int invmod(long long int i) {
  if (i == 1) return 1;
  return (1000000007 -
          ((1000000007 / i) * invmod(1000000007 % i)) % 1000000007 +
          1000000007) %
         1000000007;
}
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < INF; i++) spf[i] = i;
  for (int i = 4; i < INF; i += 2) spf[i] = 2;
  for (int i = 3; i * i < INF; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < INF; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
int64_t binpow(int64_t a, int64_t b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int64_t temp = binpow(a, b / 2);
  if (b % 2 == 0)
    return (temp * temp);
  else
    return (((temp * temp)) * a);
}
int64_t tot(int64_t n) {
  int64_t result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
void phi_1_to_n(int n) {
  vector<int> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool is_prime(int64_t n) {
  if (n == 1) return false;
  int64_t i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
void SieveOfEratosthenes() {
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  prime[0] = 0;
  for (int p = 2; p * p < INF; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i < INF; i += p) {
        prime[i] = false;
      }
    }
  }
}
void div() {
  for (int64_t i = 1; i < INF; i++) {
    for (int64_t j = i; j < INF; j += i) {
      d[j] += i;
      d[j] = d[j] % M;
    }
  }
}
vector<pair<long long, long long>> factors;
vector<pair<long long, long long>> factorize(long long N) {
  factors.clear();
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  factors = res;
  return res;
}
vector<int64_t> divisors;
void getDivisors(int64_t ind = 0, int64_t res = 1) {
  if (ind == (int)factors.size()) {
    divisors.push_back(res);
    return;
  }
  for (int64_t i = 0; i <= factors[ind].second; i++) {
    getDivisors(ind + 1, res);
    res *= factors[ind].first;
  }
}
bool isqr(int64_t n) {
  int64_t val = sqrt(n);
  return (val * val) == n;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool cmp(string a, string b) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 1) {
      if (a[i] != b[i]) {
        return b > a;
      }
    } else {
      if (a[i] != b[i]) {
        return a > b;
      }
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  string s[n];
  map<string, int> mpp;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mpp[s[i]] = i + 1;
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n; i++) cout << mpp[s[i]] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
