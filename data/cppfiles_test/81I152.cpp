#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (i % 2 ? (s[i] == '+') : (s[i] == '-'));
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << abs(pref[r] - pref[l - 1]) << endl;
    }
  }
  return 0;
}
