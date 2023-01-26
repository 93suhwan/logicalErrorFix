#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <class T>
void show(vector<vector<T>> &a) {
  for (auto &i : a) {
    for (T &j : i) cout << j << ' ';
    cout << endl;
  }
}
template <class T>
void show(vector<T> &a) {
  for (T i : a) cout << i << ' ';
  cout << endl;
}
void show(vector<string> &a) {
  for (auto &i : a) cout << i << endl;
}
template <class T>
void take(vector<T> &a) {
  for (auto &i : a) cin >> i;
}
long long digits(long long n) {
  long long k = 0;
  while (n) k++, n /= 10;
  return k;
}
bool isprime(long long n) {
  long long i;
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long power(long long x, long long y, long long MOD) {
  long long ans = 1;
  x %= MOD;
  while (y > 0) {
    if (y % 2 == 1) ans = (ans * x) % MOD;
    y /= 2;
    x = (x * x) % MOD;
  }
  return ans;
}
void sieve(vector<bool> &a, long long n) {
  long long i, j;
  a[1] = 0;
  a[0] = 0;
  long long h = sqrt(n + 1);
  for (i = 2; i < h; i++) {
    if (!a[i]) continue;
    for (j = 2 * i; j < n + 1; j += i) a[j] = 0;
  }
}
void load(unordered_map<long long, long long> &g) { g.max_load_factor(0.25); }
void sub() {}
const long long N = 1e9 + 7;
const long long M = 998244353;
void solve() {
  long long n, i, m, k, j;
  cin >> n;
  vector<long long> a(n), b(n);
  for (i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long ans = n * (n - 1) * (n - 2) / 6;
  vector<long long> a1(n + 1), b1(n + 1);
  for (i = 0; i < n; i++) {
    a1[a[i]]++;
    b1[b[i]]++;
  }
  for (i = 0; i < n; i++) {
    ans -= max(0ll, a1[a[i]] - 1) * max(0ll, b1[b[i]] - 1);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sub();
  auto start1 = high_resolution_clock::now();
  long long t = 1, s;
  cin >> t;
  for (s = 1; s < t + 1; s++) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  cerr << "Time: " << (double)duration.count() / 1000 << " ms" << endl;
  return 0;
}
