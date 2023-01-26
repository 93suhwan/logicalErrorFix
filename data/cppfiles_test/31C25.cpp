#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> act(1 << k, 0);
  for (long long i = 0; i < n; ++i) {
    long long t;
    cin >> t;
    act[t] = 1;
  }
  function<vector<vector<long long>>(long long, long long, long long)> solve =
      [&](long long l, long long r, long long ind) {
        if (l + 1 == r)
          return vector<vector<long long>>{{LLONG_MAX / 2 * (!act[l])},
                                           {-LLONG_MAX / 2 * (!act[l])},
                                           {LLONG_MAX / 2}};
        else {
          long long mid = (l + r) / 2;
          long long le = r - l;
          vector<vector<long long>> ret = {
              vector<long long>(le, LLONG_MAX / 2),
              vector<long long>(le, -LLONG_MAX / 2),
              vector<long long>(le, LLONG_MAX / 2)};
          auto q1 = solve(l, mid, ind - 1), q2 = solve(mid, r, ind - 1);
          for (long long i = 0; i < le / 2; ++i) {
            ret[0][i] = min(q1[0][i], q2[0][i] + (1 << ind));
            ret[0][i + le / 2] = min(q2[0][i], q1[0][i] + (1 << ind));
            ret[1][i + le / 2] = max(q1[1][i] + (1 << ind), q2[1][i]);
            ret[1][i] = max(q2[1][i] + (1 << ind), q1[1][i]);
            ret[2][i] = min(q1[2][i], q2[2][i]);
            ret[2][i + le / 2] = min(q1[2][i], q2[2][i]);
          }
          for (long long i = 0; i < le / 2; ++i)
            ret[2][i] = min(ret[2][i], q2[0][i] + (1 << ind) - q1[1][i]);
          for (long long i = 0; i < le / 2; ++i)
            ret[2][i + le / 2] =
                min(ret[2][i + le / 2], q1[0][i] + (1 << ind) - q2[1][i]);
          return ret;
        }
      };
  vector<long long> ans = solve(0, 1 << k, k - 1)[2];
  for (long long i = 0; i < 1 << k; ++i) cout << ans[i] << " ";
  cout << endl;
}
