#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
void MAIN() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    if (arr[i] % 2 != i % 2) {
      cout << -1 << '\n';
      return;
    }
  }
  auto reverse = [&](int x) {
    for (int i = 1; i <= x / 2; i++) swap(arr[i], arr[x - i + 1]);
  };
  vector<int> ans;
  for (int i = n; i > 1; i--) {
    if (i % 2) {
      int x = find(arr + 1, arr + n + 1, i) - arr;
      ans.push_back(x);
      reverse(x);
      x = find(arr + 1, arr + n + 1, i - 1) - arr;
      reverse(x - 1);
      ans.push_back(x - 1);
      reverse(x + 1);
      ans.push_back(x + 1);
      reverse(3);
      ans.push_back(3);
      reverse(i);
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
