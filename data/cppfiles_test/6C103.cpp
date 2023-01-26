#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j;
  long long int n, m, x, y, cont, a, b, c, d, k, z, l, mx, mn;
  cin >> n >> m;
  unordered_map<int, int> mp, mp1;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    mx = max(x, y);
    mn = min(x, y);
    mp[mn]++;
  }
  int q;
  cin >> q;
  int ans = 0, finalans = 0;
  ans = n - mp.size();
  finalans = ans;
  mp1 = mp;
  for (i = 0; i < q; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      mn = min(b, c);
      if (mp1[mn] == 0) finalans--;
      mp1[mn]++;
    } else if (a == 2) {
      cin >> b >> c;
      mn = min(b, c);
      mp1[mn]--;
      if (mp1[mn] == 0) finalans++;
    } else {
      cout << finalans << endl;
    }
  }
}
