#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
long long MOD = 998244353;
long long mod = 1000000007;
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= mod ? res - mod : res);
}
long long multiply(long long x, long long y) {
  long long res = x * y;
  return (res >= mod ? res % mod : res);
}
long long subtract(long long x, long long y) {
  long long res = x - y;
  return (res < 0 ? res + mod : res);
}
long long power(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sieve_of_eratosthenes(long long n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime[n];
}
void primeFactors(long long n) {
  while (n % 2 == 0) {
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
    }
  }
  if (n > 2) {
  }
}
long long NODiv(long long n) {
  long long cnt = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (i * i == n) {
      cnt++;
      continue;
    }
    cnt += 2;
  }
  return cnt;
}
long long nCr(long long n, long long k) {
  if (n < k) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }
  long long res = 1;
  for (long long i = n - k + 1; i <= n; ++i) res *= i;
  for (long long i = 2; i <= k; ++i) res /= i;
  return res;
}
bool isPrime(long long x) {
  for (long long d = 2; d * d <= x; d++) {
    if (x % d == 0) return false;
  }
  return true;
}
vector<vector<long long>> adj;
void addEdge(long long x, long long y) {
  adj[x].push_back(y);
  adj[y].push_back(x);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort((a).begin(), (a).end());
  vector<pair<long long, long long>> v;
  long long sec_max = a[n - 2].first;
  long long i = 0;
  while (i < n - 1) {
    if (a[n - 1].first <= sec_max) {
      sec_max = a[n - 2].first;
      long long val1 = a[n - 1].first;
      long long val2 = a[n - 1].first;
      a[n - 1].first = a[n - 2].first;
      a[n - 1].second = a[n - 2].second;
      a[n - 2].first = val1;
      a[n - 2].second = val2;
    }
    if (a[i].first == 0) {
      i++;
    }
    if (i != n - 1 and a[i].first > 0) {
      v.push_back({a[i].second, a[n - 1].second});
      a[i].first--;
      a[n - 1].first--;
    }
  }
  cout << v.size() << "\n";
  for (auto i : v) {
    cout << i.first << " " << i.second << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  long long k = 1;
  while (t--) {
    k++;
    solve();
  }
  return 0;
}
