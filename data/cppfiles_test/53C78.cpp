#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x7fffffff;
pair<long long, long long> a[100005];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  if (n == 1) {
    cout << "YES"
         << "\n";
    return;
  } else {
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i].second + 1 != a[i + 1].second) {
        cnt++;
      }
    }
    if (cnt < k) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
