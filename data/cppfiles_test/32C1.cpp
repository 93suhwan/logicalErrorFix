#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    vector<int64_t> S(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> A[i];
      S[i] = A[i] + S[i - 1];
    }
    int lo = 1, hi = sqrt(2 * n), mid;
    if (hi * (hi + 1) > 2 * n) --hi;
    while (lo != hi) {
      mid = (lo + hi + 1) / 2;
      int tot = mid * (mid + 1) / 2;
      vector<vector<int64_t>> minS(2, vector<int64_t>(n + 1, 0));
      bool found = false;
      for (int j = 1; j <= mid; ++j) {
        int k = mid + 1 - j;
        int id = j & 1;
        fill(minS[id].begin(), minS[id].end(), INF);
        for (int i = tot - (mid - j) * (mid - j + 1) / 2; i <= n; ++i) {
          int64_t sum = S[i] - S[i - k];
          if (minS[id ^ 1][i - k] < sum) {
            if (j == mid) {
              found = true;
              break;
            }
            minS[id][i] = min(minS[id][i - 1], sum);
          } else
            minS[id][i] = minS[id][i - 1];
        }
      }
      if (found)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << '\n';
  }
  return 0;
}
