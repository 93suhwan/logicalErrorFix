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
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    if (s[0] == 'a') {
      a[0] = 1;
    } else {
      a[0] = -1;
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == 'a') {
        a[i] += a[i - 1] + 1;
      } else {
        a[i] += a[i - 1] - 1;
      }
    }
    map<int, int> mapa;
    mapa[a[0]] = 1;
    bool ok = false;
    int l, r;
    for (int i = 1; i < n; i++) {
      if (mapa[a[i]] == 0) {
      } else {
        ok = true;
        l = mapa[a[i]];
        r = i + 1;
        break;
      }
      mapa[a[i]] = i + 1;
    }
    if (ok) {
      cout << l << " " << r << "\n";
    } else {
      cout << -1 << " " << -1 << "\n";
    }
    t--;
  }
}
