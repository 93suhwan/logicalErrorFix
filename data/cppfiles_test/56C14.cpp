#include <bits/stdc++.h>
using namespace std;
int k, n;
const int mod = 1000000007;
long long dp[67][6];
map<pair<long long, int>, long long> dp2;
map<long long, int> v;
set<long long> all;
bool possible(int a, int b) { return a / 2 == b / 2; }
long long solve(int t, int c) {
  if (t == 1) return 1;
  if (dp[t][c] != -1) return dp[t][c];
  long long res = 0;
  for (int i = 0; i < 6; i++)
    if (!possible(c, i)) {
      res += solve(t - 1, i);
      res %= mod;
    }
  res = (res * res) % mod;
  dp[t][c] = res;
  return res;
}
long long get(int h, long long p, int c) {
  if (all.find(p) == all.end()) return solve(h, c);
  if (v.find(p) != v.end() && v[p] != c) return 0;
  if (h == 1) return 1;
  if (dp2.find(make_pair(p, c)) != dp2.end()) return dp2[make_pair(p, c)];
  long long res = 0;
  for (int i = 0; i < 6; i++)
    if (!possible(c, i)) {
      for (int j = 0; j < 6; j++)
        if (!possible(c, j)) {
          res += (get(h - 1, 2 * p, i) * get(h - 1, 2 * p + 1, j)) % mod;
          res %= mod;
        }
    }
  dp2[make_pair(p, c)] = res;
  return res;
}
int id(string &s) {
  if (s == "white") return 0;
  if (s == "yellow") return 1;
  if (s == "green") return 2;
  if (s == "blue") return 3;
  if (s == "red") return 4;
  if (s == "orange") return 5;
}
void add(long long x) {
  while (x > 0) {
    all.insert(x);
    x /= 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    string s;
    cin >> x >> s;
    v[x] = id(s);
    add(x);
  }
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 6; j++) dp[i][j] = -1;
  long long res = 0;
  for (int i = 0; i < 6; i++) res += get(k, 1, i);
  res %= mod;
  cout << res << endl;
  return 0;
}
