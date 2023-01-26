#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<vector<long long int>> p, long long int m,
                long long int n, long long int x) {
  vector<bool> friends(n, false);
  bool is_pair = false;
  for (int i = 0; i < m; i++) {
    long long int c = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= x) {
        friends[j] = true;
        c++;
      }
    }
    if (c > 1) {
      is_pair = true;
    }
  }
  if (!is_pair) return false;
  bool ans = true;
  for (auto x : friends) {
    ans = ans && x;
  }
  return ans;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int m, n;
    cin >> m >> n;
    vector<vector<long long int>> p(m, vector<long long int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> p[i][j];
      }
    }
    long long int low = 0, high = 1e9 + 7;
    long long int ans = 0;
    while (low <= high) {
      long long int mid = low + (high - low) / 2;
      if (isPossible(p, m, n, mid)) {
        low = mid + 1;
        ans = mid;
      } else
        high = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
