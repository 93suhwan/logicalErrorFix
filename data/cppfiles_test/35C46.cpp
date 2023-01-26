#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 1e6 + 100, A = 1e6 + 100, K = 1001, INF = 2e18,
                MOD = 1e9 + 7;
long long n, a[N], g[N], prime[N];
vector<long long> v[N];
string s;
vector<long long> primes(long long e) {
  vector<long long> res;
  while (e > 1) {
    res.push_back(prime[e]);
    e /= prime[e];
  }
  return res;
}
void solve() {
  for (long long i = 2; i < N; i++) {
    if (prime[i] == 0) {
      prime[i] = i;
      for (long long j = i * i; j < N; j += i) {
        prime[j] = i;
      }
    }
  }
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (long long i = 0; i < n; i++) {
    vector<long long> pr = primes(a[i]);
    if (s[i] == '*') {
      g[i] = i;
      for (long long x : pr) {
        v[x].push_back(i);
      }
    } else {
      long long mn = INF;
      for (long long x : pr) {
        if (v[x].empty()) {
          mn = -1;
        } else {
          mn = min(mn, v[x].back());
          v[x].pop_back();
        }
      }
      g[i] = mn;
    }
  }
  long long ans = 0;
  vector<pair<long long, long long>> u;
  for (long long i = n - 1; i >= 0; i--) {
    u.push_back({g[i], i});
    while (!u.empty() && u.back().first >= i) {
      u.pop_back();
    }
    if (u.empty()) {
      ans += n - i;
    } else {
      ans += u.back().second - i;
    }
  }
  cout << ans;
}
