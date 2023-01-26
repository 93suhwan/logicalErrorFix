#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++) {
      pos[i] = {a[i], i};
    }
    sort(pos.begin(), pos.end());
    vector<bool> used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        int cnt = 0;
        int start = i;
        int curr = i;
        while (true) {
          curr = pos[curr].second;
          cnt++;
          used[curr] = true;
          if (curr == start) {
            break;
          }
        }
        ans += cnt - 1;
      }
    }
    if (ans % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
