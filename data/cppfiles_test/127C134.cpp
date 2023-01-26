#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long int n, i, x, mx = 0, cnt = 1, b = 0, c = 0, a = 0;
    string s, t, ans;
    cin >> s >> t;
    sort(s.begin(), s.end());
    n = s.size();
    for (i = 0; i < n; i++) {
      if (s[i] == t[mx]) ++mx;
      if (s[i] == 'a') a++;
      if (s[i] == 'b') b++;
      if (s[i] == 'c') c++;
      if (s[i] > 'c') ans += s[i];
    }
    if (mx < 3 or t != "abc")
      cout << s;
    else {
      bool chk = false;
      while (a--) cout << 'a';
      while (c--) cout << 'c';
      while (b--) cout << 'b';
      cout << ans;
    }
    printf("\n");
  }
  return 0;
}
