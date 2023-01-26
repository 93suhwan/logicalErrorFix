#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
inline long long sbt(long long x) { return __builtin_popcountll(x); }
inline long long mul(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return ((a % m) * (b % m)) % m;
}
inline long long add(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return (a + b) % m;
}
inline long long sub(long long a, long long b,
                     long long m = (long long)(1e9 + 7)) {
  return (a - b + m) % m;
}
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}
long long modinv(long long a, long long m = (long long)(1e9 + 7)) {
  return fastpow(a, m - 2, m);
}
bool comp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if ((b.second - b.first) == (a.second - a.first)) {
    return a.first < b.first;
  }
  return (a.second - a.first) < (b.second - b.first);
}
void solve() {
  long long n, l, r;
  cin >> n;
  vector<pair<long long, long long>> v;
  for (long i = 0; i < n; i++) {
    cin >> l >> r;
    v.push_back({l, r});
  }
  sort(v.begin(), v.end(), comp);
  vector<array<long long, 3>> ans;
  set<long long> s;
  for (auto i = 1; i <= n; i++) s.insert(i);
  for (auto i : v) {
    auto it = s.lower_bound(i.first);
    array<long long, 3> cur{i.first, i.second, *it};
    ans.push_back(cur);
    s.erase(it);
  }
  for (auto i : ans) {
    cout << i[0] << " " << i[1] << " " << i[2];
    cout << "\n";
  }
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    solve();
    cout << "\n";
  }
  return 0;
}
