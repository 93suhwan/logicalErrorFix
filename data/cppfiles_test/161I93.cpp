#include <bits/stdc++.h>
using namespace std;
void dbg() { cout << endl; }
template <typename T, typename... parameters>
void dbg(T n, parameters... remaining) {
  cout << n << " ";
  dbg(remaining...);
}
bool mark[10000001];
set<long long> prime;
void seive() {
  for (int i = 2; i < 10000001; i++) {
    if (mark[i] == false) {
      prime.insert(i);
      for (int j = i + i; j < 10000001; j += i) mark[j] = true;
    }
  }
}
long long mod = 1e9 + 7;
long long power(long long x, long long y, long long m) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power((x * x) % m, y / 2, m);
  else
    return (x * power((x * x) % m, (y - 1) / 2, m)) % m;
}
vector<long long> fact;
void pre_calc(long long n, long long mod) {
  fact.resize(n + 1, 0);
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (i % mod) * (fact[i - 1] % mod) % mod;
  }
}
long long inv(long long n, long long mod) { return power(n, mod - 2, mod); }
long long ncr(long long n, long long r, long long mod) {
  long long a = fact[n];
  long long b = inv(fact[r], mod);
  long long c = inv(fact[n - r], mod);
  return ((((a % mod) * (b % mod)) % mod) * (c % mod)) % mod;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  map<pair<long long, long long>, long long> mp;
  long long idx = -1;
  for (long long i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    if (a == 1 && b == n) {
      idx = i;
    }
    v[i] = {a, b};
    mp[v[i]] = i;
  }
  map<pair<long long, long long>, long long> ans;
  queue<pair<long long, long long> > q;
  q.push({1, n});
  while (!q.empty()) {
    auto fr = q.front();
    q.pop();
    long long l = fr.first;
    long long r = fr.second;
    if (l == r) {
      ans[fr] = l;
    }
    for (long long i = l; i <= r; i++) {
      long long mid = i;
      pair<long long, long long> p1 = {l, mid - 1};
      pair<long long, long long> p2 = {mid + 1, r};
      long long f = 0;
      if (mp.find(p1) != mp.end()) {
        q.push(p1);
        ans[fr] = mid;
        f = 1;
      }
      if (mp.find(p2) != mp.end()) {
        q.push(p2);
        ans[fr] = mid;
        f = 1;
      }
      if (f) break;
    }
  }
  for (auto it : ans) {
    dbg(it.first.first, it.first.second, it.second);
  }
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
