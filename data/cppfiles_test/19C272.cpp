#include <bits/stdc++.h>
using namespace std;
int64_t INF64 = int64_t(2e18) + 5;
int INF = int(1e9) + 5;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &a : arr) cin >> a;
  int subset = 1;
  for (int i = 0; i < n; i++) subset *= 3;
  for (int k = 1; k < subset; k++) {
    int x = k, sum = 0;
    for (int i = 0; i < n; i++) {
      int d = x % 3;
      x /= 3;
      if (d == 1) sum += arr[i];
      if (d == 2) sum -= arr[i];
    }
    if (sum == 0) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int testcases = 1;
  cin >> testcases;
  while (testcases-- > 0) solve();
}
