#include <bits/stdc++.h>
using namespace std;
const int MAXX = 2e5 + 10;
int T, n;
pair<int, int> a[MAXX];
vector<pair<int, int>> vec;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    vec.clear();
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) {
      if (!a[i].first) continue;
      for (int j = i - 1, mn; j >= 0; j--) {
        if (a[j].first) {
          mn = min(a[i].first, a[j].first);
          a[i].first -= mn;
          for (int k = 0; k < mn; k++)
            vec.push_back({a[i].second, a[j].second});
          a[j].first -= mn;
        }
      }
    }
    cout << vec.size() << '\n';
    for (auto x : vec) cout << x.first << " " << x.second << '\n';
  }
}
