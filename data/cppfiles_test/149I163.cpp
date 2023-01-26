#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 1e5 + 10;
template <typename... T>
void debug(T&... args) {
  cout << "\n==================\n";
  ((cout << args << ", "), ...);
  cout << "\n==================\n";
}
template <typename T>
void debug(vector<T>& a) {
  cout << "\n==============\n";
  for (auto& e : a) cout << e << ' ';
  cout << "\n==============\n";
}
template <typename... T>
void put(T&... args) {
  ((cout << args << " "), ...);
}
long long digit(long long a, long long b) {
  string A = to_string(a);
  string B = to_string(b);
  return A.length() + B.length();
}
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  vector<long long> a;
  if (x == 0) {
    for (auto& e : s)
      if (e == 'a') cout << e;
    cout << '\n';
    return;
  }
  long long p = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '*')
      p++;
    else {
      if (p > 0) a.push_back(p);
      p = 0;
    }
  }
  if (p > 0) a.push_back(p);
  vector<long long> d(a.size());
  unsigned long long sm = 1;
  for (long long i = d.size() - 1; i >= 0; i--) {
    d[i] = sm;
    if (digit(a[i] * k + 1, d[i]) < 18)
      sm = (a[i] * k + 1) * d[i];
    else
      sm = 1e18 + 1;
  }
  vector<long long> res(a.size());
  for (long long i = 0; i < a.size(); i++) {
    res[i] = x / d[i];
    x = x - res[i] * d[i];
  }
  long long in = 0;
  bool f = true;
  for (auto& e : s) {
    if (e == '*') {
      if (f) {
        for (long long i = 0; i < res[in]; i++) cout << "b";
        in++;
        f = false;
      }
    } else {
      cout << e;
      f = true;
    }
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
