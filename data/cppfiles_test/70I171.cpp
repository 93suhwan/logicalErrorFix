#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
long long add(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return (a + b) % MOD;
}
long long sub(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return (a - b + MOD) % MOD;
}
long long mul(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return ((a * b) % MOD + MOD) % MOD;
}
long long mod_pow(long long n, long long x) {
  int res = 1;
  while (x > 0) {
    if (x % 2 == 1) res = (res * n) % MOD;
    n = (n * n) % MOD;
    x /= 2;
  }
  return res;
}
void solve() {
  string t, order = "";
  cin >> t;
  map<char, int> m;
  int n = 0;
  for (int i = t.size() - 1; i >= 0; i--) {
    if (m[t[i]] == 0) {
      order = t[i] + order;
    }
    m[t[i]]++;
  }
  for (int i = 0; i < order.size(); i++) {
    m[order[i]] /= (i + 1);
    n += m[order[i]];
  }
  string s = t.substr(0, n);
  bool temp = true;
  set<char> used;
  int ind = n;
  for (int i = 0; i < order.size(); i++) {
    used.insert(order[i]);
    for (int j = 0; j < s.size(); j++) {
      if (ind == t.size() && used.find(s[j]) == used.end()) {
        cout << "-1\n";
        return;
      }
      if (s[j] != t[ind] && used.find(s[j]) == used.end()) {
        cout << "-1\n";
        return;
      }
      if (s[j] == t[ind]) {
        ind++;
      }
    }
  }
  if (temp) {
    cout << s << " " << order << "\n";
  } else {
    cout << "-1\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
