#include <bits/stdc++.h>
using namespace std;
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, a, b;
    cin >> n >> k;
    vector<bool> used(n, false);
    vector<pair<int, int> > segs;
    for (int i = 0; i < (int)(k); i++) {
      cin >> a >> b;
      --a, --b;
      if (a > b) {
        swap(a, b);
      }
      segs.push_back({a, b});
      used[a] = 1;
      used[b] = 1;
    }
    if (k < n) {
      int x = 0;
      while (used[x]) {
        x++;
      }
      int y = x;
      for (int i = k; i < n; i++) {
        do {
          y++;
        } while (used[y]);
      }
      for (int i = k; i < n; i++) {
        segs.push_back({x, y});
        used[x] = 1;
        used[y] = 1;
        do {
          x++;
        } while (used[x]);
        do {
          y++;
        } while (used[y]);
      }
    }
    int ans = 0;
    for (size_t i = 0; i < segs.size(); i++) {
      auto ch1 = segs[i];
      for (size_t j = i + 1; j < segs.size(); j++) {
        auto [x, y] = ch1;
        auto [u, v] = segs[j];
        if (x > u) {
          swap(x, u);
          swap(y, v);
        }
        if (y > u && v > y) {
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
