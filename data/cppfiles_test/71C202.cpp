#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 500;
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
const int md = 1e9 + 7;
const int MOD = 100003;
const int Mod = 998244353;
const int M = 30;
const long long moD = 100000;
const int D = 233;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return (!b ? a : gcd(b, a % b)); }
int T;
long long k;
string n;
string solve1(string s) {
  string res(s.size(), '9');
  for (int i = 8; i >= 0; i--) {
    string t(s.size(), char(i + '0'));
    if (t >= s) res = t;
  }
  return res;
}
string solve2(string s) {
  string res = solve1(s);
  for (char a = '0'; a <= '8'; a++) {
    for (char b = a + 1; b <= '9'; b++) {
      int flag = 1;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] < b) {
          string t = s;
          if (t[i] < a)
            t[i] = a;
          else
            t[i] = b;
          for (int k = i + 1; k < (int)s.size(); k++) {
            t[k] = a;
          }
          if (t >= s) res = min(res, t);
        }
        if (s[i] != a && s[i] != b) {
          flag = 0;
          break;
        }
      }
      if (flag) return n;
    }
  }
  return res;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (k == 1)
      cout << solve1(n) << endl;
    else
      cout << solve2(n) << endl;
  }
  return 0;
}
