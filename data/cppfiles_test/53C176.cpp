#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    auto solve = [&]() {
      for (int i = 0; i < n - 1; ++i)
        if (a[i + 1].second != a[i].second + 1) --k;
      return k > 0;
    };
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
