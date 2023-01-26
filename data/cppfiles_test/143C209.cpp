#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long t, n, cnt[N], f[N], a[N];
map<long long, long long, greater<long long>> m;
map<long long, long long>::iterator it;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    m.clear();
    for (long long i = 0; i <= n; i++) cnt[i] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      m[a[i]]++;
      cnt[a[i]]++;
    }
    f[0] = m[0];
    cout << f[0] << ' ';
    for (long long i = 1; i <= n; i++) {
      if (f[i - 1] == -1)
        f[i] = -1;
      else {
        if (cnt[i - 1])
          f[i] = f[i - 1] - cnt[i - 1] + cnt[i];
        else {
          while (1) {
            it = m.upper_bound(i);
            if (it != m.end() && (*it).second < 2)
              m.erase(it);
            else
              break;
          }
          if (it == m.end())
            f[i] = -1;
          else {
            f[i] = f[i - 1] + cnt[i] + i - (*it).first - 1;
            (*it).second--;
            if ((*it).second < 2) m.erase(it);
          }
        }
      }
      cout << f[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
