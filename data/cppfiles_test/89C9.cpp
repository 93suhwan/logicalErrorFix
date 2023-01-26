#include <bits/stdc++.h>
using namespace std;
template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vector<T>, greater<T>>;
const long long mod = 1e12L + 7;
const long long INF = 1e18L + 5;
const long long mxN = 2e5 + 1;
bool prime[200002];
void SieveOfEratosthenes(long long n) {
  for (long long i = 1; i <= 200002; i++) {
    prime[i] = true;
  }
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long long> pt;
  for (long long i = 0; i < n; i++) {
    if (prime[i + 2] || (i + 2) <= 1000) {
      pt.push_back(i + 2);
    }
    bool ok = false;
    for (auto x : pt) {
      if (v[i] % x != 0) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  SieveOfEratosthenes(200000);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) solve();
  return 0;
}
