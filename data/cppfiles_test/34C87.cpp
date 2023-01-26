#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
int gcdExtended(int a, int b, int *x, int *y);
int modInverse(int b, int m) {
  int x, y;
  int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long sumbincoef(int N, int k) {
  long long bincoef = 1, sum = 1;
  int i;
  for (i = 1; i < k; i++) {
    long long val = ((N - i + 1) % mod * modInverse(i, mod)) % mod;
    bincoef = (bincoef % mod * val) % mod;
    if (i % 2 == 0) sum = (sum + bincoef) % mod;
  }
  return sum % mod;
}
const int N = 300000 + 10;
long long factorialNumInverse[N + 1];
long long naturalNumInverse[N + 1];
long long fact[N + 1];
void InverseofNumber(long long p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long p) {
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long Binomial(long long N, long long R, long long p) {
  long long ans =
      ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
  return ans;
}
int parent[N], ran[N];
void make_set(int v) {
  parent[v] = v;
  ran[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (ran[a] < ran[b]) swap(a, b);
    parent[b] = a;
    if (ran[a] == ran[b]) ran[a]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(
      (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  long long p = mod;
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);
  int t = 1;
  while (t > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(8192, 1e6);
    unordered_map<int, vector<int>> mapa;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mapa[a[i]].push_back(i);
    }
    dp[0] = -1;
    for (long long i = 0; i <= 5000; i++) {
      for (long long j = 0; j < 8192; j++) {
        auto it = upper_bound(mapa[i].begin(), mapa[i].end(), dp[j]);
        if (it == mapa[i].end()) continue;
        dp[i ^ j] = min(dp[i ^ j], *it);
      }
    }
    vector<int> ans;
    for (int i = 0; i < 8192; i++) {
      if (dp[i] < 1e6) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    t--;
  }
}
