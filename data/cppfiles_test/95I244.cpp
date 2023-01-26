#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int s, n;
    cin >> s >> n;
    int copy = s;
    int sum = 0;
    vector<int> d;
    while (s) {
      d.push_back(s % 10);
      sum += (s % 10);
      s /= 10;
    }
    s = copy;
    vector<int> ans(n);
    int pwr[10] = {1,      10,      100,      1000,      10000,
                   100000, 1000000, 10000000, 100000000, 1000000000};
    if (sum >= n) {
      int cur = 0;
      for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[i]; j++) {
          ans[cur] += pwr[i];
          if (cur < n - 1) cur++;
        }
      }
      for (int x : ans) cout << x << " ";
      cout << endl;
    } else {
      int cur = 0;
      int left = n;
      int sleft = s;
      for (int i = d.size() - 1; i >= 0; i--) {
        for (int j = 0; j < d[i]; j++) {
          if (sleft - (d[i] - j) * pwr[i] < left - (d[i] - j)) break;
          ans[cur] += pwr[i];
          sleft -= pwr[i];
          left -= 1;
          if (cur < n - 1) cur++;
        }
      }
      int big = sleft - left + 1;
      for (int i = 0; i < cur; i++) cout << ans[i] << " ";
      for (int i = cur; i < n - 1; i++) cout << 1 << " ";
      cout << big << '\n';
    }
  }
  return 0;
}
