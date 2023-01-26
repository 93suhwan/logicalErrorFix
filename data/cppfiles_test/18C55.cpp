#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX_SIZE = 1000005;
const long long int MAXN = 100000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, k;
    cin >> n >> k;
    vector<vector<long long int>> v;
    vector<long long int> track(2 * n, 0);
    for (long long int i = 0; i < k; i++) {
      long long int x, y;
      cin >> x >> y;
      x--;
      y--;
      v.push_back({x, y});
      track[x] = 1;
      track[y] = 1;
    }
    long long int t1 = 0;
    long long int t2 = 0;
    for (long long int i = 0; i < 2 * n; i++) {
      if (track[i] == 0) {
        t1 = i;
        break;
      }
    }
    for (long long int i = t1; i < 2 * n; i++) {
      if (track[i] == 0) {
        if (t2 == n - k) {
          t2 = i;
          break;
        }
        t2++;
      }
    }
    for (long long int i = 0; i < n - k; i++) {
      v.push_back({t1, t2});
      track[t1] = 1;
      track[t2] = 1;
      t1++;
      t2++;
      if (i == n - k - 1) {
        break;
      }
      while (track[t1] != 0) {
        t1++;
      }
      while (track[t2] != 0) {
        t2++;
      }
    }
    long long int ans = 0;
    for (long long int i = 0; i < n - 1; i++) {
      for (long long int j = i + 1; j < n; j++) {
        if ((v[i][0] - v[j][0]) * (v[i][1] - v[j][0]) * (v[i][0] - v[j][1]) *
                (v[i][1] - v[j][1]) <
            0) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
