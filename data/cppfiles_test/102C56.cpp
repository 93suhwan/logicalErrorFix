#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long int l = s.size();
    const long long int inf = 1e18;
    long long int h = 0, v = 0;
    long long int maxr = 0, maxu = 0, maxl = 0, maxd = 0;
    long long int hleeway = 0, vleeway = 0;
    long long int startx = 0, starty = 0;
    for (long long int i = 0; i < l; i++) {
      if (s[i] == 'L')
        h--;
      else if (s[i] == 'R')
        h++;
      else if (s[i] == 'U')
        v++;
      else
        v--;
      maxr = max(maxr, h);
      maxl = min(maxl, h);
      maxd = min(maxd, v);
      maxu = max(maxu, v);
      hleeway = max(hleeway, maxr - maxl);
      vleeway = max(vleeway, maxu - maxd);
      if (hleeway < m && vleeway < n) {
        startx = abs(maxl);
        starty = abs(maxu);
      } else {
        cout << starty + 1 << " " << startx + 1 << "\n";
        goto done;
      }
    }
    cout << starty + 1 << " " << startx + 1 << "\n";
  done:;
  }
  return 0;
}
