#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using vi = vector<int>;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
int t, n, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    int res = 0;
    for (int i = k * 2 + 1; i <= n; i++) res += a[i];
    int mx = 0;
    for (int i = 1; i <= k * 2; i++) {
      int now = 0;
      for (int j = 1; j <= k * 2; j++) {
        if (a[j] == a[i]) now++;
      }
      mx = max(mx, now);
    }
    if (mx > k) res += (mx - (k * 2 - mx)) / 2;
    cout << res << '\n';
  }
  return 0;
}
