#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    int m, n, joy;
    cin >> m >> n;
    vector<int> frnd(n, 0);
    int c = INT_MIN;
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
      vector<int> shop;
      for (int j = 0; j < n; j++) {
        cin >> joy;
        shop.push_back(joy);
        frnd[j] = max(frnd[j], joy);
      }
      sort(shop.begin(), shop.end());
      c = max(c, shop[n - 2]);
    }
    ans = min(c, *(min_element(frnd.begin(), frnd.end())));
    cout << ans << '\n';
  }
}
