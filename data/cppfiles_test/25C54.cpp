#include <bits/stdc++.h>
using namespace std;
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modi(long long int a, long long int m = 1000000007) {
  return powm(a, m - 2, m);
}
void pre() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  pre();
  long long int test;
  cin >> test;
  while (test--) {
    string s, t;
    cin >> s >> t;
    string tp1 = "";
    bool as = false;
    for (long long int i = 0; i < s.length(); i++) {
      long long int j = 0;
      if (s[i] != t[j])
        continue;
      else {
        long long int id = i;
        while (s[id] == t[j] && id < s.length() && j < t.length()) {
          id++;
          j++;
          long long int idx = id - 2, tj = j;
          while (s[idx] == t[tj] && idx >= 0 && tj < t.length()) {
            idx--;
            tj++;
          }
          if (tj == t.length()) {
            as = true;
            break;
          }
        }
        if (as) {
          break;
        }
        id -= 2;
        while (s[id] == t[j] && id >= 0 && j < t.length()) {
          id--;
          j++;
        }
        if (j == t.length()) {
          as = true;
          break;
        }
      }
      if (as) break;
    }
    if (as)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
