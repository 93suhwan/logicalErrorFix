#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
void remin(T &a, V b) {
  a > b ? a = b : a = a;
}
template <class T, class V>
void remax(T &a, V b) {
  a < b ? a = b : a = a;
}
const long long MAXN = 1e5 + 5;
void test_case() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  bool ok = true;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1' && t[i] == '1') {
      ok = false;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) test_case();
  return 0;
}
