#include <bits/stdc++.h>
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
const long long INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<pair<int, int>> bit(n + 2, {INF, INF});
    function<void(int, pair<int, int>, vector<pair<int, int>>&)> update =
        [&](int id, pair<int, int> val, vector<pair<int, int>>& v) {
          id = id + 1;
          while (id <= n + 1) {
            v[id] = min(v[id], val);
            id += id & -id;
          }
        };
    function<pair<int, int>(int, vector<pair<int, int>>&)> query =
        [&](int id, vector<pair<int, int>>& v) {
          id = id + 1;
          pair<int, int> ret = {INF, INF};
          while (id) {
            ret = min(ret, v[id]);
            id -= id & -id;
          }
          return ret;
        };
    int resp = INF;
    update(0, {0, 0}, bit);
    for (int i = 0; i < k; i++) {
      vector<pair<int, int>> newbit(n + 2, {INF, INF});
      resp = INF;
      for (int j = 1; j <= n; j++) {
        pair<int, int> men = query(v[j] - 1, bit);
        if (men.second > j) continue;
        if (v[j] - v[men.second] <= j - men.second) {
          resp = min(resp, j - v[j]);
          update(v[j], {j - v[j], j}, newbit);
        }
      }
      bit = newbit;
    }
    cout << (resp == INF ? -1 : resp) << '\n';
  }
  return 0;
}
