#include <bits/stdc++.h>
using ll = long long;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> vec[i];
    }
    int ans = 0;
    std::vector<int> visited(n, -1);
    std::vector<int> dp(n, -1);
    for (int i = 0; i < n; ++i) {
      if (visited[i] == -1) {
        int cnt = 0;
        int index = i;
        bool zero = false;
        while (visited[index] == -1) {
          visited[index] = 1;
          if (vec[index] == 0) {
            zero = true;
            break;
          }
          ++cnt;
          index = (index - d + n) % n;
        }
        if (zero) {
          dp[i] = cnt;
        } else if (index != i) {
          dp[i] = cnt + dp[index];
        } else {
          ans = -1;
          break;
        }
        int j = i;
        int sub = 0;
        while (j != index && vec[index] != 0) {
          dp[j] = dp[i] - sub;
          ++sub;
          j = (j - d + n) % n;
        }
      }
    }
    if (ans != -1) {
      for (auto x : dp) {
        ans = std::max(ans, x);
      }
    }
    std::cout << ans << '\n';
  }
}
