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
  vector<pair<long long, pair<long long, long long>>> vp;
  while (n--) {
    long long l, r;
    cin >> l >> r;
    vp.push_back({r - l, {l, r}});
  }
  sort(vp.begin(), vp.end());
  map<long long, long long> mp;
  vector<vector<long long>> ans;
  for (auto i : vp) {
    long long a = i.second.first;
    long long b = i.second.second;
    for (long long i = a; i <= b; i++) {
      if (mp.find(i) == mp.end()) {
        ans.push_back({a, b, i});
        mp[i]++;
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << i[0] << " " << i[1] << " " << i[2] << endl;
    ;
  }
  cout << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
