#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  v.push_back(n + 1);
  sort(v.begin(), v.end());
  stack<int> t;
  vector<int> ans(n + 1, -1);
  for (int i = 0, j = 0, l = 0; i <= n; i++) {
    if (v[j] != i) {
      ans[i] = l;
      if (t.empty()) {
        break;
      } else {
        l += (i - t.top());
        t.pop();
      }
    } else {
      int s = v[j], r = j;
      j++;
      while (s == v[j]) {
        t.push(v[j]);
        j++;
      }
      ans[i] = j - r + l;
    }
  }
  for (auto i : ans) {
    cout << i << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
