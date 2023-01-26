#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
void DBG() { cerr << "]" << '\n'; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int d = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        d++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        d--;
    }
    if (!d) {
      cout << s << "\n";
      continue;
    }
    if (d > 0) {
      if (s[n - 2] == 'a' && s[n - 1] == 'b') {
        s[n - 1] = 'a';
        d--;
      }
      for (int i = 0; i < n - 2; i++) {
        if (d > 0 && s[i] == 'a' && s[i + 1] == 'b') {
          if (s[i + 2] == 'b') {
            s[i + 2] = 'a';
            d--;
          }
        }
      }
      assert(d == 0);
    } else {
      if (s[n - 2] == 'b' && s[n - 1] == 'a') {
        s[n - 1] = 'b';
        d++;
      }
      for (int i = 0; i < n - 2; i++) {
        if (d < 0 && s[i] == 'b' && s[i + 1] == 'a') {
          if (s[i + 2] == 'a') {
            s[i + 2] = 'b';
            d++;
          }
        }
      }
      assert(d == 0);
    }
    cout << s << "\n";
  }
  return 0;
}
