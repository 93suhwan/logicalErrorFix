#include <bits/stdc++.h>
using namespace std;
long long task() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  reverse(a.begin(), a.end());
  vector<long long> cum(n + 1);
  cum[0] = 0;
  for (int i = 0; i < n; i++) {
    cum[i + 1] = cum[i] + a[i];
  }
  vector<vector<long long>> k_ans(
      1, vector<long long>(n + 1, numeric_limits<long long>::max()));
  long long k = 1;
  while (true) {
    k_ans.emplace_back(n + 1, -1);
    long long curr_max = -1;
    for (long long start = k * (k - 1) / 2; start <= n - k; start++) {
      long long curr = cum[start + k] - cum[start];
      if (curr < k_ans[k - 1][start]) {
        curr_max = max(curr_max, curr);
      }
      k_ans[k][start + k] = curr_max;
    }
    if (curr_max == -1) {
      return k - 1;
    }
    k++;
  }
}
int main() {
  cin.tie(nullptr);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cout << task() << '\n';
  }
  return 0;
}
