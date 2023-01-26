#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b > (n - 2)) {
    cout << -1 << endl;
    return;
  }
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 1);
  if (a == b) {
    for (int i = 1; i < n && a > 0 && b > 0; i += 2) {
      swap(ans[i], ans[i + 1]);
      --a, --b;
    }
  } else if (a < b) {
    for (int i = 0; i < n && b > 0; i += 2) {
      swap(ans[i], ans[i + 1]);
      --a, --b;
    }
  } else {
    for (int i = n - 2; i >= 0 && a > 0; i -= 2) {
      swap(ans[i], ans[i + 1]);
      --a, --b;
    }
  }
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
}
