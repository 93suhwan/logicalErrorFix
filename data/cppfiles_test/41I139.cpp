#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (i - 1 >= 0 && s[i - 1] == s[i]) a[i] = 1;
    if (i - 2 >= 0 && s[i - 2] == s[i]) a[i] = 2;
  }
  vector<int> sa(n + 1);
  for (int i = 0; i < n; ++i) sa[i + 1] = sa[i] + a[i];
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if (l + 3 >= r) {
      int ans = 0;
      for (int j = l + 1; j <= r; ++j) {
        int f = 0;
        if (j - 1 >= l && s[j - 1] == s[j]) f = 1;
        if (j - 2 >= l && s[j - 2] == s[j]) f = 1;
        ans += f;
      }
      cout << ans << '\n';
    } else {
      int ans = sa[r + 1] - sa[l + 2];
      if (s[l] == s[l + 1]) ++ans;
      if (s[l] == s[l + 2] || s[l + 1] == s[l + 2]) ++ans;
      cout << ans << endl;
    }
  }
}
