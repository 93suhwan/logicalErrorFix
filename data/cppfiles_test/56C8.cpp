#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846L;
const long double E = 2.71828182845904523536L;
const int INF = (1 << 30) - 1;
const long long LINF = 1e18;
const long double eps = 1e-7;
const long long mod = 1e9 + 7;
unordered_map<long long, long long> u[65][10];
vector<pair<int, int> > v;
long long ans[65];
int k, n;
unordered_map<long long, int> match;
unordered_set<long long> skip;
long long solve(long long idx, int lvl, int c) {
  if (u[lvl][c].count(idx)) {
    return u[lvl][c][idx];
  }
  long long& r = u[lvl][c][idx];
  if (match.count(idx)) {
    if (match[idx] != c) {
      r = 0;
      return r;
    }
  }
  if (lvl == k) {
    r = 1;
    return 1;
  }
  if (!skip.count(idx)) {
    r = ans[lvl];
    return r;
  }
  long long m1 = 0, m2 = 0;
  for (int j = 0; j < 6; j++) {
    if (j == c || j == (c ^ 1)) {
      continue;
    }
    m1 += solve(idx * 2, lvl + 1, j);
    m2 += solve(idx * 2 + 1, lvl + 1, j);
  }
  m1 %= mod;
  m2 %= mod;
  r = m1 * m2 % mod;
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  cin >> k >> n;
  unordered_map<string, int> g;
  g["white"] = 0;
  g["yellow"] = 1;
  g["green"] = 2;
  g["blue"] = 3;
  g["red"] = 4;
  g["orange"] = 5;
  for (int i = 0; i < n; i++) {
    long long x;
    string s;
    cin >> x >> s;
    match[x] = g[s];
    while (x) {
      skip.insert(x);
      x /= 2;
    }
  }
  ans[k] = 1;
  for (int i = k - 1; i >= 1; i--) {
    ans[i] = (4 * ans[i + 1]) % mod;
    ans[i] = (ans[i] * ans[i]) % mod;
  }
  long long r = 0;
  for (int i = 0; i < 6; i++) {
    r += solve(1, 1, i);
  }
  cout << r % mod << '\n';
}
