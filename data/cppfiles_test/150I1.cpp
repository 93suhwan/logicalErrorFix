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
vector<int> parent(400000 + 1), ran(400000 + 1);
void make_set(int v) {
  parent[v] = v;
  ran[v] = 0;
}
int find_set(int a) {
  if (parent[a] == a) {
    return a;
  }
  return parent[a] = find_set(parent[a]);
}
int union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (ran[a] < ran[b]) {
    parent[a] = b;
  } else if (ran[a] > ran[b]) {
    parent[b] = a;
  } else {
    parent[b] = a;
    ran[a]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  long long p = mod;
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);
  int t = 1;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans = max(ans, a[i] / 3);
      a[i] = a[i] % 3;
      if (a[i] == 1) {
        cnt1++;
      } else if (a[i] == 2) {
        cnt2++;
      }
    }
    if (cnt1 > 0 && cnt2 > 0) {
      ans += 2;
    } else if (cnt1 > 0 || cnt2 > 0) {
      ans++;
    }
    cout << ans << "\n";
    t--;
  }
}
