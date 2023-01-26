#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MOD = 998244353;
bool solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.length();
  long long m = t.length();
  long long i, j;
  for (i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
    if (s[j] == t[i]) {
      j--;
      i--;
    } else {
      j -= 2;
    }
  }
  return i < 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
