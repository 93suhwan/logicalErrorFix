#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h;
  cin >> w >> h;
  int k;
  cin >> k;
  int mn1 = INT_MAX, mx1 = -1;
  int x;
  for (int i = 0; i < k; i++) {
    cin >> x;
    mn1 = min(x, mn1);
    mx1 = max(x, mn1);
  }
  cin >> k;
  int mn2 = INT_MAX, mx2 = -1;
  for (int i = 0; i < k; i++) {
    cin >> x;
    mn2 = min(x, mn2);
    mx2 = max(x, mn2);
  }
  cin >> k;
  int mn3 = INT_MAX, mx3 = -1;
  for (int i = 0; i < k; i++) {
    cin >> x;
    mn3 = min(x, mn3);
    mx3 = max(x, mn3);
  }
  cin >> k;
  int mn4 = INT_MAX, mx4 = -1;
  for (int i = 0; i < k; i++) {
    cin >> x;
    mn4 = min(x, mn4);
    mx4 = max(x, mn4);
  }
  long long a1 = 1ll * h * (mx1 - mn1);
  long long a2 = 1ll * h * (mx2 - mn2);
  long long a3 = 1ll * w * (mx3 - mn3);
  long long a4 = 1ll * w * (mx4 - mn4);
  cout << max({a1, a2, a3, a4}) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
