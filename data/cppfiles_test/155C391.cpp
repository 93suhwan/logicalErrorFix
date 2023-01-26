#include <bits/stdc++.h>
using namespace std;
int main() {
  long t, n, l1, l2, l3, i, j, l, r, k;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long> v(n), x(n);
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    cin >> s;
    set<pair<long, long> > z;
    set<pair<long, long> > o;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        z.insert({v[i], i});
      } else
        o.insert({v[i], i});
    }
    long y = 1;
    for (auto it : z) {
      x[it.second] = y;
      y++;
    }
    for (auto it : o) {
      x[it.second] = y;
      y++;
    }
    for (i = 0; i < n; i++) {
      cout << x[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
