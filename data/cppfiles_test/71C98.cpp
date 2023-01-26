#include <bits/stdc++.h>
using namespace std;
int cases(1), t;
const int64_t Mod = 1e9 + 7, Mod1 = 998244353;
template <typename T>
T Power(T n, T k) {
  T x = 1;
  while (k) {
    if (k & 1) x *= n;
    n *= n;
    k >>= 1;
  }
  return x;
}
template <typename T>
T Power(T n, T k, T M) {
  n %= M;
  T res = 1;
  while (k) {
    if (k & 1) res = res * n % M;
    n = n * n % M;
    k >>= 1;
  }
  return res;
}
string one(string s) {
  string ans;
  for (char i = '9'; i >= '0'; i--) {
    string t(s.size(), i);
    if (t >= s) {
      ans = t;
    }
  }
  return ans;
}
string two(string s) {
  string ans = one(s);
  for (char a = '0'; a <= '9'; a++) {
    for (char b = a + 1; b <= '9'; b++) {
      bool okay = false;
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] < b) {
          string t = s;
          if (s[i] < a) {
            t[i] = a;
          } else
            t[i] = b;
          for (long long j = i + 1; j < s.size(); j++) {
            t[j] = a;
          }
          if (ans > t) ans = t;
        }
        if (s[i] != a && s[i] != b) {
          okay = true;
          break;
        }
      }
      if (!okay) return s;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  for (cin >> t; cases <= t; cases++) {
    string n;
    long long k;
    cin >> n >> k;
    if (k == 1)
      cout << one(n);
    else
      cout << two(n);
    cout << '\n';
  }
  return 0;
}
