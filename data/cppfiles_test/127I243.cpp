#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long int n, i, b, x, mx = 0, cnt = 1;
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    n = s.size();
    for (i = 0; i < n; i++) {
      if (s[i] == t[mx]) ++mx;
    }
    if (mx < 3)
      cout << s;
    else {
      bool chk = false;
      for (i = 0; i < n; i++) {
        if (s[i] == t[2] and chk == false) {
          chk = true;
        } else if (s[i] != s[i + 1] and cnt == 1) {
          cout << s[i] << t[2];
          cnt = 0;
        } else
          cout << s[i];
      }
    }
    printf("\n");
  }
  return 0;
}
