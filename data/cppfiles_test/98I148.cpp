#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
      char s;
      cin >> s;
      if (i == 0) {
        pref[i] = (s == 'a' ? 1 : 0);
      } else {
        pref[i] = pref[i - 1] + (s == 'a' ? 1 : 0);
      }
    }
    bool has = false;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((pref[i] - pref[j - 1]) * 2 == i - j + 1) {
          cout << i + 1 << " " << j + 1 << '\n';
          has ^= true;
          goto end;
        }
      }
    }
  end:
    if (!has) {
      cout << "-1 -1" << '\n';
    }
  }
  return 0;
}
