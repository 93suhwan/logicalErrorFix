#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long int INF = 1e18;
const long long int MOD = 1e9 + 7;
inline long long int mod_pow(long long int a, long long int b) {
  long long int res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
inline long long int mod_inv(long long int a, long long int b) {
  return mod_pow(a, MOD - 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int TT = 1;
  cin >> TT;
  while (TT--) {
    long long int n, m, k = 0;
    string s, x;
    cin >> s >> x;
    k = x.length() - 1;
    long long int pos = s.length() - 1;
    for (long long int i = (s.length() - 1); i >= (0); --i) {
      if (k == -1) break;
      if (s[i] == x[k] && (abs(pos - i) % 2 == 0)) {
        pos = i - 1;
        k--;
      }
    }
    if (k == -1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
