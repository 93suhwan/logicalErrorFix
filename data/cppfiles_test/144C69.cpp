#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t, n, m, k;
  cin >> t;
  vector<int> cnt;
  vector<bool> d;
  while (t--) {
    cin >> n >> m >> k;
    int u = n % m, v = n / m + 1;
    cnt.assign(n, 0);
    if (u == 0) u = m, v--;
    int x = u * v * k;
    int y = x / n, z = x % n;
    for (int i = 0; i < z; ++i) cnt[i] = y + 1;
    for (int i = z; i < n; ++i) cnt[i] = y;
    int id = 0;
    for (int _ = 0; _ < k; ++_) {
      d.assign(n, false);
      for (int i = 0; i < u; ++i) {
        cout << v << " ";
        for (int j = 0; j < v; ++j) {
          while (cnt[id] == 0) id++;
          cout << id + 1 << " ";
          cnt[id]--;
          d[id] = true;
          id++;
          if (id == n) id = 0;
        }
        cout << endl;
      }
      int idx = 0;
      for (int i = u; i < m; ++i) {
        cout << v - 1 << " ";
        for (int j = 0; j < v - 1; ++j) {
          while (d[idx]) idx++;
          cout << idx + 1 << " ";
          idx++;
        }
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
