#include <bits/stdc++.h>
using namespace std;
long long i, j, k, t, m, x, y, z, n;
const long long INF = 1e9 + 7;
inline void debugMode() {}
int main() {
  int t;
  scanf("%d", &t);
  for (int g = 1; g <= t; g++) {
    cin >> x;
    vector<long long> v, w;
    long long flag = 0;
    for (long long i = 0; i < x; i++) {
      if (flag) {
        cin >> y;
        v.push_back(y);
        flag = 0;
      } else {
        cin >> y;
        w.push_back(y);
        flag = 1;
      }
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    long long fv = 0, fw = 0;
    for (auto it : v) {
      if (it % v[0] != 0) fv++;
      if (it % w[0] == 0) fw++;
    }
    for (auto it : w) {
      if (it % w[0] != 0) fw++;
      if (it % v[0] == 0) fv++;
    }
    if (fw == 0)
      cout << w[0] << "\n";
    else if (fv == 0)
      cout << v[0] << "\n";
    else
      cout << 0 << "\n";
  }
}
