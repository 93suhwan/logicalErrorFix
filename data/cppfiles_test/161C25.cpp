#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i].first == a[i].second) {
      cout << a[i].first << " " << a[i].second << " " << a[i].first << "\n";
    } else {
      int min1 = a[i].first - 1;
      for (int j = 0; j < n; j++) {
        if (j != i) {
          if (a[i].first <= a[j].first and a[j].second <= a[i].second) {
            if (a[i].first == a[j].first) {
              min1 = max(min1, a[j].second);
            }
          }
        }
      }
      cout << a[i].first << " " << a[i].second << " " << min1 + 1 << "\n";
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
