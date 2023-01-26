#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, char>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    bool check = true;
    for (int i = 1; i <= n; i++) {
      if ((a[i - 1].first > n && a[i - 1].second == 'R') ||
          (a[i - 1].first <= 0 && a[i - 1].second == 'B')) {
        check = false;
        break;
      }
      if (a[i - 1].first <= 0) a[i - 1].first = 1;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
      if ((a[i - 1].first < i && a[i - 1].second == 'B') ||
          (a[i - 1].first > i && a[i - 1].second == 'R')) {
        check = false;
        break;
      }
    }
    if (check)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
