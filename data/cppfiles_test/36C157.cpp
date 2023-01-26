#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
long long fac[1001];
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
void SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) {
    }
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrModPFermat(long long n, long long r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void dfs(long long v, vector<vector<long long>> &adj,
         vector<long long> &visited) {
  for (long long u : adj[v]) {
    if (!visited[u]) {
      visited[u] = 1;
    }
  }
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a"
         << "\n";
    return;
  }
  if (n == 2) {
    cout << "ab"
         << "\n";
    return;
  }
  if (n == 3) {
    cout << "abc"
         << "\n";
    return;
  }
  long long i;
  if (n & 1) {
    int cnt = (n - 2) / 2;
    string s = "";
    for (i = 0; i < cnt; i++) {
      s += 'a';
    }
    s += 'b';
    s += 'c';
    for (i = 0; i < cnt + 1; i++) {
      s += 'a';
    }
    cout << s << "\n";
  } else {
    int cnt = (n - 1) / 2;
    string s = "";
    for (i = 0; i < cnt; i++) {
      s += 'a';
    }
    s += 'b';
    for (i = 0; i < cnt + 1; i++) {
      s += 'a';
    }
    cout << s << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 2;
  switch (test) {
    case 1:
      solve();
      break;
    case 2: {
      long long t;
      cin >> t;
      while (t--) {
        solve();
      }
    }; break;
  }
}
