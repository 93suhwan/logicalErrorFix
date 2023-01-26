#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using tlll = tuple<long long, long long, long long>;
using tllll = tuple<long long, long long, long long, long long>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, m = 0, n = 0, p = 0,
            q = 0, mod = 998244353;
  long double pi = 3.1415926535, ad = 0, bd = 0, cd = 0, dd = 0;
  string s1, s2;
  char moji, moja;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    bool dou = true;
    if (b % 2 == 0) dou = false;
    for (int j = 0; j < b; j++) {
      d = c;
      cin >> c;
      if (c <= d && j != 0) {
        dou = false;
      }
    }
    cout << (dou ? "NO" : "YES") << endl;
  }
  return 0;
}
