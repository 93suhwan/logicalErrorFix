#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int Q = 0; Q < T; Q++) {
    int n, q;
    cin >> n >> q;
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<int> pref(n);
    pref[0] = s[0] == '+' ? 1 : -1;
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] + (i % 2 == 0 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
    }
    int l, r;
    int temp;
    for (int i = 0; i < q; i++) {
      cin >> l >> r;
      l--;
      r--;
      if ((r - l + 1) % 2 == 1) {
        cout << 1 << endl;
        continue;
      }
      temp = l == 0 ? 0 : pref[l - 1];
      temp = pref[r] - temp;
      if (temp != 0) {
        cout << 2 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}
