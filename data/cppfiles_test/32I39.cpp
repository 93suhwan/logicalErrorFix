#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<int64_t> sum(N + 1);
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];
    vector<int> dp = a;
    for (int i = N - 1; i >= 1; i--) {
      dp[i] = max(dp[i], dp[i + 1]);
    }
    constexpr int inf = INT_MAX;
    int k = 2;
    while (true) {
      int d = k * (k + 1) / 2 - 1;
      vector<int> nxt(N + 1, inf);
      for (int i = N - d; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        int64_t range = sum[i + k - 1] - sum[i - 1];
        if (range < dp[i + k]) {
          nxt[i] = min<int>(nxt[i], range);
        }
      }
      if (nxt[1] == inf) {
        cout << k - 1 << '\n';
        break;
      } else {
        dp = move(nxt);
        k++;
      }
    }
  }
  return 0;
}
