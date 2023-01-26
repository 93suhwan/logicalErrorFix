#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 2e5;
const int LOGN = 18;
const int MOD = (int)1e9 + 7;
void clear() {}
void precalc() {}
void gen_tests() {}
int mult(int a, int b) { return (a * (long long)b) % MOD; }
int sum(int a, int b) { return (a + b) % MOD; }
int bin_pow(int value, long long power) {
  if (power == 0) return 1;
  int val = bin_pow(mult(value, value), power >> 1);
  return power & 1 ? mult(value, val) : val;
}
map<pair<long long, int>, int> cache;
set<long long> visited_nums;
map<long long, int> given;
int recurse(long long value, int color) {
  if (cache.count({value, color})) return cache[{value, color}];
  if (given.count(value) && given[value] != color) return 0;
  int rst = 1;
  long long values[2] = {value * 2, value * 2 + 1};
  for (auto u : values) {
    if (visited_nums.count(u) == 0) continue;
    int vals = 0;
    for (int i = 1; i < 3; ++i) {
      vals = sum(vals, recurse(u, (i + color) % 3));
    }
    rst = mult(rst, vals);
  }
  return cache[{value, color}] = rst;
}
void solve() {
  int k;
  cin >> k;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long v;
    string name;
    cin >> v >> name;
    if (name == "white" || name == "yellow")
      given[v] = 0;
    else if (name == "green" || name == "blue")
      given[v] = 1;
    else
      given[v] = 2;
  }
  int rst = 0;
  for (auto u : given) {
    long long value = u.first;
    while (value) {
      visited_nums.insert(value);
      value = value >> 1;
    }
  }
  for (int i = 0; i < 3; ++i) {
    rst = sum(rst, recurse(1, i));
  }
  rst = mult(rst, bin_pow(2, (1LL << k) - 1 - n));
  rst = mult(rst, bin_pow(2, (1LL << k) - 1 - visited_nums.size()));
  cout << rst << '\n';
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
