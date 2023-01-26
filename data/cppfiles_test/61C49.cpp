#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sort2(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
const long long INF = 1e18;
const int mod = 1e9 + 7;
inline int add(int x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) return x + mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int power(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
inline int inv(int x) { return power(x, mod - 2); }
const long long FACTORIAL_SIZE = 1.1e6;
long long fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
void gen_factorial(long long n) {
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  ifact[n] = inv(fact[n]);
  for (long long i = n - 1; i >= 2; i--) {
    ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
  }
}
long long nck(long long n, long long k) {
  long long den = (ifact[k] * ifact[n - k]) % mod;
  return (den * fact[n]) % mod;
}
const int N = 2e5 + 5;
vector<long long> diff[N], topic[N];
long long n;
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    diff[i].clear();
    topic[i].clear();
  }
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    diff[b].push_back(a);
    topic[a].push_back(b);
  }
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (long long i = 1; i <= n; i++) {
    if (diff[i].size() < 2) continue;
    for (auto it : diff[i]) {
      if (topic[it].size() < 2) continue;
      long long ds = diff[i].size() - 1;
      long long ts = topic[it].size() - 1;
      long long temp = (ds * ts);
      ans -= temp;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  cin >> tc;
  long long i = 1;
  while (tc--) {
    solve();
    i++;
  }
  return 0;
}
