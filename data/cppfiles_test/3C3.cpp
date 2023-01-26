#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  vector<char> v(n, '0');
  if (n > 1) v[0] = '1';
  int res = 0;
  while (1) {
    bool f = false;
    if (n == 1) {
      if (v[0] == '0') f = true;
    } else {
      if (v[n - 2] == '0' and v[n - 1] == '0' and n > 2)
        f = true;
      else if (v[n - 2] == '2' and v[n - 1] == '5')
        f = true;
      else if (v[n - 2] == '5' and v[n - 1] == '0')
        f = true;
      else if (v[n - 2] == '7' and v[n - 1] == '5')
        f = true;
    }
    if (f) {
      char x = '.';
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (s[i] == '_')
          continue;
        else if (s[i] == 'X') {
          if (x == '.')
            x = v[i];
          else {
            if (x != v[i]) ok = false;
          }
        } else if (s[i] != v[i])
          ok = false;
      }
      if (ok) res++;
    }
    bool ed = true;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] == '9') {
        v[i] = '0';
      } else {
        v[i]++;
        ed = false;
        break;
      }
    }
    if (ed) break;
  }
  cout << res << endl;
}
