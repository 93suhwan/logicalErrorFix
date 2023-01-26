#include <bits/stdc++.h>
using namespace std;
long long powerMod(int x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = powerMod(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    long long w, h;
    cin >> w >> h;
    vector<long long> v[4];
    for (int i = (0); i < (4); i++) {
      int k;
      cin >> k;
      for (int j = (0); j < (k); j++) {
        int a;
        cin >> a;
        v[i].push_back(a);
      }
    }
    cout << max(max(v[0][v[0].size() - 1] - v[0][0],
                    v[1][v[1].size() - 1] - v[1][0]) *
                    h,
                max(v[2][v[2].size() - 1] - v[2][0],
                    v[3][v[3].size() - 1] - v[3][0]) *
                    w)
         << '\n';
  }
}
