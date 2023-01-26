#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 7;
int n;
long long k;
pair<long long, long long> a[maxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long ans = 0;
    cin >> n;
    cin >> k;
    long long mx = -1e18;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first;
      a[i].second = 1;
      mx = max(mx, abs(a[i].first));
    }
    sort(a + 1, a + n + 1);
    while (a[n].first > 0) {
      if (a[n].second < 0) {
        if (a[n - 1].first > 0) a[n - 1].second += a[n].second;
        n--;
        continue;
      }
      long long T = a[n].second / k;
      long long buff = 0;
      if (T * k != a[n].second) {
        ++T;
        buff = k - a[n].second % k;
      }
      T = T * 2 * a[n].first;
      ans += T;
      if (a[n - 1].first > 0) {
        a[n - 1].second -= buff;
      }
      n--;
    }
    int pos = 1;
    while (a[pos].first < 0) {
      if (a[pos].second < 0) {
        if (a[pos + 1].first < 0) a[pos + 1].second += a[pos].second;
        pos++;
        continue;
      }
      long long T = a[pos].second / k;
      long long buff = 0;
      if (T * k != a[pos].second) {
        ++T;
        buff = k - a[pos].second % k;
      }
      T = T * 2 * abs(a[pos].first);
      ans += T;
      if (a[pos + 1].first < 0) {
        a[pos + 1].second -= buff;
      }
      pos++;
    }
    cout << ans - mx << '\n';
  }
}
