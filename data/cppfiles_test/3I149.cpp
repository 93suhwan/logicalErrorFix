#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int _runtimeTerror_() {
  string s;
  cin >> s;
  if ((long long)s.size() == 1) {
    if (s == "0" || s == "_" || s == "X") {
      cout << "1\n";
      return 0;
    } else {
      cout << "0\n";
      return 0;
    }
  }
  reverse(s.begin(), s.end());
  long long ans = 0;
  int n = (long long)s.size();
  vector<pair<char, char>> tmp = {
      {'0', '0'}, {'0', '5'}, {'5', '2'}, {'5', '7'}};
  for (auto [i, j] : tmp) {
    if (s[0] == '_' || s[0] == 'X' || s[0] == i) {
      if (s[1] == '_' || s[1] == 'X' || s[1] == j) {
        if (s[0] == 'X' && s[1] == 'X' && i != j) {
          continue;
        }
        int cnt = 0;
        int x = 0;
        for (int id = 2; id < n; ++id) {
          if (s[id] == '_') {
            ++cnt;
          }
          if (s[id] == 'X') {
            ++x;
          }
        }
        char xc = s[0] == 'X' ? i : (s[1] == 'X' ? j : 0);
        long long val = power(10, cnt);
        if (s.back() == '_') {
          val /= 10;
          val *= 9;
        }
        if (xc != 0) {
          if (xc == '0' && (s.back() == '0' || s.back() == 'X')) {
            continue;
          }
        } else {
          if (s.back() == '0') {
            continue;
          }
          if (s.back() == 'X') {
            val *= 9;
          } else if (x > 0) {
            val *= 10;
          }
        }
        ans += val;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
