#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, ss, e, a = 0, b = 0, v = 0, j, k;
    cin >> n;
    string s;
    cin >> s;
    ss = 0;
    e = s.size();
    for (i = 0; i < n; i++) {
      if (s[i] == 'a')
        a++;
      else
        b++;
    }
    if (n == 1) {
      cout << -1 << " " << -1 << "\n";
      continue;
    }
    for (j = 2; j <= n; j += 2) {
      for (k = 0; k < n; k++) {
        v = 0;
        ss = k;
        for (i = k; i < k + j && i < n; i++) {
          if (s[i] == 'a')
            v++;
          else
            v--;
        }
        e = i - 1;
        if (v == 0) break;
      }
      if (v == 0) break;
    }
    if (v == 0)
      cout << ss + 1 << " " << e + 1 << "\n";
    else
      cout << -1 << " " << -1 << "\n";
  }
  return 0;
}
