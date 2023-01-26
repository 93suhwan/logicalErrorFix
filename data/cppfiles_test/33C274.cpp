#include <bits/stdc++.h>
const int MAX = (const int)(1e5 + 11);
using namespace std;
static void solve(std::int32_t test) {
  vector<int64_t> A(MAX);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    int64_t res = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j <= 10; ++j) {
        int64_t mx = 0;
        int64_t mn = 1e9;
        int cnt = 0;
        for (int k = i; k <= i + j; ++k) {
          if (0 <= k && k < N) {
            mx = max(mx, A[k]);
            mn = min(mn, A[k]);
            cnt++;
          }
        }
        if (cnt > 1) res = max(res, mx * mn);
      }
    }
    cout << res << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  solve(0);
  return 0;
}
