#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c, d, e, x, y, z, t;
  string s, ss;
  char q, w;
  bool h;
  while (cin >> x) {
    while (x--) {
      cin >> s;
      map<char, long long> n;
      for (long long i = 0; i < s.size(); i++) {
        n[s[i]]++;
        if (n[s[i]] > 2) n[s[i]] = 2;
      }
      y = 0;
      for (auto i : n) y += i.second;
      cout << y / 2 << "\n";
    }
  }
}
