#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const long long mod = (long long)1e9 + 7;
const long long MOD = (long long)998244353;
const long long INF = (long long)1e18;
inline long long add(long long a, long long b) {
  return (a + b >= mod ? a + b - mod : a + b);
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
bool f(string &a, string &b) {
  for (long long i = 0; i <= (long long)(b).size() - (long long)(a).size();
       ++i) {
    string t = b.substr(i, (long long)(a).size());
    if (t == a) {
      bool ok = 1;
      for (long long j = i - 1; j >= 0; --j)
        if (b[j] == '0') {
          ok = 0;
          break;
        }
      if (!ok) continue;
      for (long long j = i + (long long)(a).size(); j < (long long)(b).size();
           ++j)
        if (b[j] == '0') {
          ok = 0;
          break;
        }
      if (ok) {
        return 1;
      }
    }
  }
  return 0;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES\n";
    return;
  }
  if (y % 2 == 0) {
    cout << "NO\n";
    return;
  }
  string a, b;
  while (x) a += '0' + x % 2, x /= 2;
  while (y) b += '0' + y % 2, y /= 2;
  reverse((a).begin(), (a).end());
  reverse((b).begin(), (b).end());
  if ((long long)(a).size() > (long long)(b).size()) {
    cout << "NO\n";
    return;
  }
  if (f(a, b)) {
    cout << "YES\n";
    return;
  }
  while (a.back() == '0') a.pop_back();
  if (f(a, b)) {
    cout << "YES\n";
    return;
  }
  reverse((a).begin(), (a).end());
  if (f(a, b))
    cout << "YES";
  else
    cout << "NO";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  solve();
  return 0;
}
