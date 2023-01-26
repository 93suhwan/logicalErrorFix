#include <bits/stdc++.h>
using namespace std;
long long ans, n, x;
vector<int> dp;
vector<pair<int, int>> A;
int main() {
  cin >> n;
  int curr = 0;
  dp.assign(n + 1, 0);
  A.resize(n + 1);
  A[0] = {-1000000, 0};
  for (int i = 1; i <= n; i++) {
    cin >> x;
    A[i] = {i - x, x};
  }
  sort(A.begin(), A.end());
  for (int i = 1; i <= n; i++) {
    if (A[i].first < 0)
      continue;
    else {
      int val = A[i].second;
      if (val > dp[curr]) {
        curr++;
        dp[curr] = val;
      } else {
        int l = 0, r = curr, mid;
        while (r - l > 1) {
          mid = (l + r) / 2;
          if (val <= dp[mid])
            r = mid;
          else
            l = mid;
        }
        dp[r] = val;
      }
    }
  }
  cout << curr << endl;
}
