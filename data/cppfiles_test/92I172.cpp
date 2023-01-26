#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amn(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amx(T &x, U y) {
  if (x < y) x = y;
}
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 5e5 + 5;
void solve() {
  string s;
  cin >> s;
  long long n = s.size(), m = 0;
  for (long long i = 0; i < n; i++) {
    long long j = i;
    while (j < n and s[j] == s[i]) {
      j++;
    }
    m++;
    i = j - 1;
  }
  if (m % 2 == 0) {
    for (long long i = 0; i < n; i++) {
      long long j = i;
      while (j < n and s[j] == s[i]) {
        j++;
      }
      if ((j - i) == 1) {
        if (s[i] == 'a')
          s[i] = 'b';
        else
          s[i] = 'a';
        cout << s << endl;
        return;
      }
    }
    for (long long i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        swap(s[i], s[i - 1]);
        cout << s << endl;
        return;
      }
    }
  }
  cout << s << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  return 0;
}
