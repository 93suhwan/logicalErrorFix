#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200005];
long long solve() {
  sort(a, a + n);
  long long ns = 0, m = a[0], ans = a[0];
  for (int i = 1; i < n; i++) {
    ns += m;
    m = a[i] - ns;
    ans = max(ans, m);
  }
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve() << '\n';
  }
  return 0;
}
