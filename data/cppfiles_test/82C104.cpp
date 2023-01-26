#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int pref[n + 1];
    memset(pref, 0, sizeof(pref));
    set<int> arr[2 * n + 5];
    for (int i = 0; i < 2 * n + 5; i++) {
      set<int> ss;
      arr[i] = ss;
    }
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '+') {
        if (i % 2 == 1) {
          pref[i] = pref[i - 1] + 1;
        } else {
          pref[i] = pref[i - 1] - 1;
        }
      } else {
        if (i % 2 == 1) {
          pref[i] = pref[i - 1] - 1;
        } else {
          pref[i] = pref[i - 1] + 1;
        }
      }
      arr[pref[i] + n].insert(i);
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      int val = pref[r] - pref[l - 1];
      if (val == 0) {
        cout << 0 << endl;
      } else {
        if (abs(val) % 2 == 1) {
          if (val < 0) {
            val--;
          } else {
            val++;
          }
          int half = pref[l - 1] + val / 2;
          half += n;
          auto it = arr[half].lower_bound(l);
          int res = *it;
          cout << 1 << endl;
          cout << res << endl;
        } else {
          int diff = pref[r] - pref[r - 1];
          val -= diff;
          if (val < 0) {
            val--;
          } else {
            val++;
          }
          int half = pref[l - 1] + val / 2;
          half += n;
          auto it = arr[half].lower_bound(l);
          int res = *it;
          cout << 2 << endl;
          cout << res << " " << r << endl;
        }
      }
    }
  }
  return 0;
}
