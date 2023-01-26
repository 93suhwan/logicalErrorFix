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
      cin >> a >> b;
      long long n[a];
      vector<long long> h;
      map<long long, long long> m;
      for (long long i = 0; i < a; i++) {
        cin >> n[i];
        m[n[i]]++;
        if (m[n[i]] == b)
          h.push_back(0);
        else
          h.push_back(m[n[i]]);
      }
      for (auto i : h) cout << i << " ";
      cout << "\n";
    }
  }
}
