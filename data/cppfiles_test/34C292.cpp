#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void yes(bool y) {
  if (y)
    yes();
  else
    no();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int &i : vec) cin >> i;
    long long ans = -1e18;
    for (int i = 0; i < n; i++) {
      for (int j = max(i + 1, n - k - 2); j < n; j++) {
        ans = max(
            ans, long long(i + 1) * (j + 1) - long long(k) * (vec[i] | vec[j]));
      }
    }
    cout << ans << "\n";
  }
}
