#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b) {
  return (a % 998244353 + b % 998244353 +
          ((8000000000000000064LL) / 998244353) * 998244353) %
         998244353;
}
long long sub(long long a, long long b) {
  return (a % 998244353 - b % 998244353 +
          ((8000000000000000064LL) / 998244353) * 998244353) %
         998244353;
}
long long mul(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353) +
          ((8000000000000000064LL) / 998244353) * 998244353) %
         998244353;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long fact[1000007] = {0};
long long expo(long long x, long long y) {
  long long res = 1;
  x = x % 998244353;
  while (y > 0) {
    if (y & 1) res = (1ll * res * x) % 998244353;
    y = y >> 1;
    x = (1ll * x * x) % 998244353;
  }
  return res;
}
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 1000007; i++)
    fact[i] = (fact[i - 1] * i) % 998244353;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  res = fact[n];
  res = (res * (expo(fact[r], 998244353 - 2))) % 998244353;
  res = (res * (expo(fact[n - r], 998244353 - 2))) % 998244353;
  return res;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int const N = 1e3 + 9;
long long const INF = 2e18 + 5;
long long dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
long long dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
char dr[4] = {'R', 'L', 'D', 'U'};
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.first > b.first;
  }
  return a.second < b.second;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[m];
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end(), cmp);
  long long ans = 0;
  for (long long i = 1; i < m; i++) {
    for (long long j = i - 1; j >= 0; j--) {
      if (a[j] < a[i]) ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
