#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 100;
int n;
vector<int> v[N], p, q;
map<int, int> mp;
signed main() {
  int T = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) v[i].clear();
    for (int i = 0; i < n; i++) {
      int x;
      for (int j = 0; j < 5; j++) {
        cin >> x;
        v[i].push_back(x);
      }
    }
    int F = 0;
    for (int i = 0; i < (1 << n); i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          sum++;
        }
      }
      if (sum == n / 2) {
        p.clear(), q.clear(), mp.clear();
        for (int j = 0; j < n; j++) {
          if (i & (1 << j)) {
            p.push_back(j);
          } else {
            q.push_back(j);
          }
        }
        for (int j = 0; j < 5; j++) {
          int f = 1;
          for (int k = 0; k < p.size(); k++) {
            if (v[p[k]][j] == 0) {
              f = 0;
              break;
            }
          }
          if (f) mp[j] = 1;
        }
        for (int j = 0; j < 5; j++) {
          int f = 1;
          for (int k = 0; k < q.size(); k++) {
            if (v[q[k]][j] == 0) {
              f = 0;
              break;
            }
          }
          if (f) {
            if (!mp[j]) {
              F = 1;
              break;
            }
          }
        }
        if (F) break;
      }
      if (F) break;
    }
    if (F)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
